using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.sensor_msgs
{
    public class PointCloud2
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public PointCloud2(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Header _header;
        public Header header
        {
            get
            {
                if (_header == null)
                {
                    _header = new Header(_pdu.GetData<IPdu>("header"));
                }
                return _header;
            }
            set
            {
                _header = value;
                _pdu.SetData("header", value.GetPdu());
            }
        }
        public uint height
        {
            get => _pdu.GetData<uint>("height");
            set => _pdu.SetData("height", value);
        }
        public uint width
        {
            get => _pdu.GetData<uint>("width");
            set => _pdu.SetData("width", value);
        }
        private PointField[] _fields;
        public PointField[] fields
        {
            get
            {
                if (_fields == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("fields");
                    _fields = new PointField[fieldPdus.Length];
                    PointField[] result = new PointField[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _fields[i] = new PointField(fieldPdus[i]);
                    }
                }
                return _fields;
            }
            set
            {
                _fields = new PointField[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _fields[i] = value[i];
                }
                _pdu.SetData("fields", fieldPdus);
            }
        }
        public bool is_bigendian
        {
            get => _pdu.GetData<bool>("is_bigendian");
            set => _pdu.SetData("is_bigendian", value);
        }
        public uint point_step
        {
            get => _pdu.GetData<uint>("point_step");
            set => _pdu.SetData("point_step", value);
        }
        public uint row_step
        {
            get => _pdu.GetData<uint>("row_step");
            set => _pdu.SetData("row_step", value);
        }
        public byte[] data
        {
            get => _pdu.GetDataArray<byte>("data");
            set => _pdu.SetData("data", value);
        }
        public bool is_dense
        {
            get => _pdu.GetData<bool>("is_dense");
            set => _pdu.SetData("is_dense", value);
        }
    }
}
