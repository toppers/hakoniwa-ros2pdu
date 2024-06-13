#ifndef _pdu_primitive_ctypes_H_
#define _pdu_primitive_ctypes_H_

#define HAKO_PDU_MAX_ARRAY_SIZE 10
#define HAKO_STRING_SIZE    128

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int8_t Hako_int8;
typedef uint8_t Hako_uint8;
typedef int16_t Hako_int16;
typedef uint16_t Hako_uint16;
typedef int32_t Hako_int32;
typedef uint32_t Hako_uint32;
typedef int64_t Hako_int64;
typedef uint64_t Hako_uint64;

typedef float Hako_float32;
typedef double Hako_float64;

typedef char Hako_string;
typedef int Hako_bool;

typedef struct {
        char data[HAKO_STRING_SIZE];
} Hako_cstring;

#define HAKO_PDU_META_DATA_MAGICNO      0x12345678
#define HAKO_PDU_META_DATA_VERSION      0x00000001

typedef struct {
    uint32_t magicno;
    uint32_t version;
    uint32_t base_off;
    uint32_t heap_off;
    uint32_t total_size;
} HakoPduMetaDataType;

#define HAKO_ALIGNMENT_SIZE sizeof(void*)
#define HAKO_ALIGN_UP(addr, alignment) (((addr) + ((alignment) - 1)) & ~((alignment) - 1))
#define HAKO_ALIGN_SIZE(size, alignment) (((size) + ((alignment) - 1)) & ~((alignment) - 1))

#define HAKO_PDU_META_DATA_SIZE()   HAKO_ALIGN_SIZE(sizeof(HakoPduMetaDataType), HAKO_ALIGNMENT_SIZE)

/*
 * Memory Alignment
 * 
 *  _____________ 
 * | PduMetaData |
 *  _____________  <--- base_off
 * | BaseData    |
 *  _____________  <--- heap_off
 * | HeapData    |
 *  -------------
 */

#define HAKO_PDU_METADATA_IS_INVALID(meta) \
    (((meta)->magicno != HAKO_PDU_META_DATA_MAGICNO) || ((meta)->version != HAKO_PDU_META_DATA_VERSION))

#define HAKO_GET_BASE_PTR(top_ptr, meta) (((char*)(top_ptr)) + (meta)->base_off)
#define HAKO_GET_HEAP_PTR(top_ptr, meta) (((char*)(top_ptr)) + (meta)->heap_off)
#define HAKO_GET_TOP_PTR(base_ptr) (((char*)(base_ptr)) - HAKO_PDU_META_DATA_SIZE())


static inline int hako_pdu_get_fixed_data(const char* buffer, char* base_ptr, int base_size, int buffer_size)
{
    HakoPduMetaDataType *meta = (HakoPduMetaDataType*)buffer;
    if (HAKO_PDU_METADATA_IS_INVALID(meta)) {
        return -1;
    }
    if (buffer_size < meta->base_off + base_size) {
        // バッファサイズが不足している場合のエラー処理
        return -1;
    }
    memcpy(base_ptr, &buffer[meta->base_off], base_size);
    return 0;
}

static inline int hako_pdu_put_fixed_data(char* buffer, const char* base_ptr, int base_size, int buffer_size)
{
    HakoPduMetaDataType *meta = (HakoPduMetaDataType*)buffer;
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->base_off = HAKO_PDU_META_DATA_SIZE();
    meta->heap_off = meta->base_off + base_size;
    if (buffer_size < meta->heap_off) {
        // バッファサイズが不足している場合のエラー処理
        return -1;
    }
    memcpy(&buffer[meta->base_off], base_ptr, base_size);
    return 0;
}
static inline void* hako_create_empty_pdu(int base_size, int heap_size)
{
    int total_size = HAKO_PDU_META_DATA_SIZE() + HAKO_ALIGN_SIZE(base_size, HAKO_ALIGNMENT_SIZE) + HAKO_ALIGN_SIZE(heap_size, HAKO_ALIGNMENT_SIZE);

    // Allocate PDU memory
    char* top_ptr = (char*)malloc(total_size);
    if (top_ptr == NULL) {
        return NULL;
    }
    memset(top_ptr, 0, total_size);
    // Set metadata at the top
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(top_ptr);
    meta->magicno = HAKO_PDU_META_DATA_MAGICNO;
    meta->version = HAKO_PDU_META_DATA_VERSION;
    meta->base_off = HAKO_PDU_META_DATA_SIZE();
    meta->heap_off = HAKO_PDU_META_DATA_SIZE() + HAKO_ALIGN_SIZE(base_size, HAKO_ALIGNMENT_SIZE);
    meta->total_size = total_size;
    return HAKO_GET_BASE_PTR(top_ptr, meta);
}

static inline void* hako_get_top_ptr_pdu(void *base_ptr)
{
    char* top_ptr = (char*)HAKO_GET_TOP_PTR(base_ptr);
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(top_ptr);

    // Validate magic number and version
    if (HAKO_PDU_METADATA_IS_INVALID(meta)) {
        return NULL; // Invalid PDU metadata
    }
    return top_ptr;
}
static inline HakoPduMetaDataType* hako_get_pdu_meta_data(void *base_ptr)
{
    void* top_ptr = hako_get_top_ptr_pdu(base_ptr);
    if (top_ptr == NULL) {
        return NULL;
    }
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(top_ptr);
    return meta;
}
static inline void* hako_get_heap_ptr_pdu(void *base_ptr)
{
    void* top_ptr = HAKO_GET_TOP_PTR(base_ptr);
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(top_ptr);

    // Validate magic number and version
    if (HAKO_PDU_METADATA_IS_INVALID(meta)) {
        return NULL; // Invalid PDU metadata
    }
    return HAKO_GET_HEAP_PTR(top_ptr, meta);
}

static inline void* hako_get_base_ptr_pdu(void *top_ptr)
{
    HakoPduMetaDataType* meta = (HakoPduMetaDataType*)(top_ptr);
    // Validate magic number and version
    if (HAKO_PDU_METADATA_IS_INVALID(meta)) {
        return NULL; // Invalid PDU metadata
    }
    return HAKO_GET_BASE_PTR(top_ptr, meta);
}
static inline int hako_destroy_pdu(void *base_ptr)
{
    void* top_ptr = hako_get_top_ptr_pdu(base_ptr);
    if (top_ptr == NULL) {
        return -1;
    }
    free(top_ptr);
    return 0;
}

#endif /* _pdu_primitive_ctypes_H_ */