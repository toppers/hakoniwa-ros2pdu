#ifndef _pdu_primitive_ctypes_H_
#define _pdu_primitive_ctypes_H_

#define HAKO_PDU_MAX_ARRAY_SIZE 10
#define HAKO_STRING_SIZE    128

#include <stdint.h>

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
    uint32_t top_off;
    uint32_t total_size;
    uint32_t varray_off;
} HakoPduMetaDataType;

#endif /* _pdu_primitive_ctypes_H_ */