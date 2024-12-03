using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class SimpleVarray
    {
        protected internal readonly IPdu _pdu;

        public SimpleVarray(IPdu pdu)
        {
            _pdu = pdu;
        }
        public sbyte[] data
        {
            get => _pdu.GetDataArray<sbyte>("data");
            set => _pdu.SetData("data", value);
        }
        public sbyte[] fixed_array
        {
            get => _pdu.GetDataArray<sbyte>("fixed_array");
            set => _pdu.SetData("fixed_array", value);
        }
        public int p_mem1
        {
            get => _pdu.GetData<int>("p_mem1");
            set => _pdu.SetData("p_mem1", value);
        }
    }
}
