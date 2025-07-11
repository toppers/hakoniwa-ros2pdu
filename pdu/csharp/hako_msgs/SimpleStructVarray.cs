using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.hako_msgs
{
    public class SimpleStructVarray
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public SimpleStructVarray(IPdu pdu)
        {
            _pdu = pdu;
        }
        public int aaa
        {
            get => _pdu.GetData<int>("aaa");
            set => _pdu.SetData("aaa", value);
        }
        public string[] fixed_str
        {
            get => _pdu.GetDataArray<string>("fixed_str");
            set => _pdu.SetData("fixed_str", value);
        }
        public string[] varray_str
        {
            get => _pdu.GetDataArray<string>("varray_str");
            set => _pdu.SetData("varray_str", value);
        }
        private SimpleVarray[] _fixed_array;
        public SimpleVarray[] fixed_array
        {
            get
            {
                if (_fixed_array == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("fixed_array");
                    _fixed_array = new SimpleVarray[fieldPdus.Length];
                    SimpleVarray[] result = new SimpleVarray[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _fixed_array[i] = new SimpleVarray(fieldPdus[i]);
                    }
                }
                return _fixed_array;
            }
            set
            {
                _fixed_array = new SimpleVarray[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _fixed_array[i] = value[i];
                }
                _pdu.SetData("fixed_array", fieldPdus);
            }
        }
        private SimpleVarray[] _data;
        public SimpleVarray[] data
        {
            get
            {
                if (_data == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("data");
                    _data = new SimpleVarray[fieldPdus.Length];
                    SimpleVarray[] result = new SimpleVarray[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _data[i] = new SimpleVarray(fieldPdus[i]);
                    }
                }
                return _data;
            }
            set
            {
                _data = new SimpleVarray[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _data[i] = value[i];
                }
                _pdu.SetData("data", fieldPdus);
            }
        }
    }
}
