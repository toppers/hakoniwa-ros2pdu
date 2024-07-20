#ifndef _PDU_PRIMITIVE_CTYPES_CONV_HPP_
#define _PDU_PRIMITIVE_CTYPES_CONV_HPP_

#include "pdu_primitive_ctypes.h"
#include "ros_primitive_types.hpp"
#include <string>
#include <array>
#include <vector>

#define M_SIZE(type, mem)   sizeof(((type *)0)->mem)
#define M_ARRAY_SIZE(type, mem_type, mem)       (M_SIZE(type, mem) / sizeof(mem_type))

template <class PduPrimitiveType, class RosPrimitiveType> 
void hako_convert_pdu2ros(PduPrimitiveType &src, RosPrimitiveType &dst)
{
    dst = src;
    return;
}
template <class PduPrimitiveType, class RosPrimitiveType> 
int hako_convert_pdu2ros_array(PduPrimitiveType src[], int src_len, RosPrimitiveType &dst, int dst_len)
{
    int ret = 0;
    int len = dst_len;
    if (src_len < dst_len) {
        len = src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    return ret;
}

template <class PduPrimitiveType, class RosPrimitiveType> 
int hako_convert_pdu2ros_array(PduPrimitiveType src[], int src_len, std::vector<RosPrimitiveType> &dst, int dst_len)
{
    if (dst_len < src_len) {
        dst.resize(src_len);
    }
    for (int i = 0; i < src_len; i++) {
        dst[i] = src[i];
    }
    return 0;
}

template <class RosPrimitiveType, class PduPrimitiveType> 
void hako_convert_ros2pdu(RosPrimitiveType &src, PduPrimitiveType &dst)
{
    dst = src;
    return;
}
template <class RosPrimitiveType, class PduPrimitiveType> 
int hako_convert_ros2pdu_array(RosPrimitiveType &src, int src_len, PduPrimitiveType &dst, int dst_len)
{
    int ret = 0;
    int len = dst_len;
    if (src_len < dst_len) {
        len = src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = src[i];
    }
    return ret;
}

template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_string(Hako_cstring src[], std::array<std::string, _dst_len> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        dst[i] = std::string(src[i].data);
    }
    return ret;
}
template<int _src_len, int _dst_len>
int hako_convert_pdu2ros_array_string(Hako_cstring src[], std::vector<std::string> &dst)
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    dst.resize(len);
    for (int i = 0; i < len; i++) {
        dst[i] = std::string(src[i].data);
    }
    return ret;
}
static inline int hako_convert_pdu2ros_array_string_varray(const Hako_cstring* src, std::vector<std::string> &dst, int len)
{
    int ret = 0;
    dst.resize(len);
    for (int i = 0; i < len; i++) {
        dst[i] = std::string(src[i].data);
    }
    return ret;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_string(std::array<std::string, _src_len> &src, Hako_cstring dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        int cplen = src[i].length();
        if (cplen >= (HAKO_STRING_SIZE - 1)) {
            cplen = HAKO_STRING_SIZE - 2;
        }
        else {
            cplen = src[i].length();
        }
        for (int j = 0; j < cplen; j++) {
            dst[i].data[j] = src[i][j];
        }
        dst[i].data[cplen] = '\0';
    }
    return ret;
}

static inline int hako_convert_ros2pdu_array_string_varray(const std::vector<std::string> &src, Hako_cstring *dst)
{
    int ret = 0;
    int len = src.size();
    for (int i = 0; i < len; i++) {
        int cplen = src[i].length();
        if (cplen >= (HAKO_STRING_SIZE - 1)) {
            cplen = HAKO_STRING_SIZE - 2;
        }
        else {
            cplen = src[i].length();
        }
        for (int j = 0; j < cplen; j++) {
            dst[i].data[j] = src[i][j];
        }
        dst[i].data[cplen] = '\0';
    }
    return ret;
}

template<int _src_len, int _dst_len>
int hako_convert_ros2pdu_array_string(std::vector<std::string> &src, Hako_cstring dst[])
{
    int ret = 0;
    int len = _dst_len;
    if (_dst_len > _src_len) {
        len = _src_len;
        ret = -1;
    }
    for (int i = 0; i < len; i++) {
        int cplen = src[i].length();
        if (cplen >= (HAKO_STRING_SIZE - 1)) {
            cplen = HAKO_STRING_SIZE - 2;
        }
        else {
            cplen = src[i].length();
        }
        for (int j = 0; j < cplen; j++) {
            dst[i].data[j] = src[i][j];
        }
        dst[i].data[cplen] = '\0';
    }
    return ret;
}

#define hako_convert_pdu2cpp hako_convert_pdu2ros
#define hako_convert_cpp2pdu hako_convert_ros2pdu
#define hako_convert_cpp2pdu_array hako_convert_ros2pdu_array

#endif /* _PDU_PRIMITIVE_CTYPES_CONV_HPP_ */