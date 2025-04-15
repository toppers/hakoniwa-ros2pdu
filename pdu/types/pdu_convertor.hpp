#pragma once

namespace hako::pdu
{
    template<typename CppType, typename Convertor>
    class PduConvertor
    {
        Convertor conv;
    
    public:
        bool pdu2cpp(char* top_ptr, CppType& cppData)
        {
            return conv.pdu2cpp(top_ptr, cppData);
        }
    
        int cpp2pdu(CppType& cppData, char* pdu_buffer, int buffer_len)
        {
            return conv.cpp2pdu(cppData, pdu_buffer, buffer_len);
        }
    };
}
