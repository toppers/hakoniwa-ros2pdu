using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.std_msgs
{
    public class MultiArrayLayout
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public MultiArrayLayout(IPdu pdu)
        {
            _pdu = pdu;
        }
        private MultiArrayDimension[] _dim;
        public MultiArrayDimension[] dim
        {
            get
            {
                if (_dim == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("dim");
                    _dim = new MultiArrayDimension[fieldPdus.Length];
                    MultiArrayDimension[] result = new MultiArrayDimension[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _dim[i] = new MultiArrayDimension(fieldPdus[i]);
                    }
                }
                return _dim;
            }
            set
            {
                _dim = new MultiArrayDimension[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _dim[i] = value[i];
                }
                _pdu.SetData("dim", fieldPdus);
            }
        }
        public uint data_offset
        {
            get => _pdu.GetData<uint>("data_offset");
            set => _pdu.SetData("data_offset", value);
        }
    }
}
