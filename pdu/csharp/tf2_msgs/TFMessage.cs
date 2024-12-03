using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;
using hakoniwa.pdu.msgs.builtin_interfaces;
using hakoniwa.pdu.msgs.geometry_msgs;
using hakoniwa.pdu.msgs.std_msgs;

namespace hakoniwa.pdu.msgs.tf2_msgs
{
    public class TFMessage
    {
        protected internal readonly IPdu _pdu;

        public TFMessage(IPdu pdu)
        {
            _pdu = pdu;
        }
        private TransformStamped[] _transforms;
        public TransformStamped[] transforms
        {
            get
            {
                if (_transforms == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("transforms");
                    _transforms = new TransformStamped[fieldPdus.Length];
                    TransformStamped[] result = new TransformStamped[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _transforms[i] = new TransformStamped(fieldPdus[i]);
                    }
                }
                return _transforms;
            }
            set
            {
                _transforms = new TransformStamped[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i]._pdu;
                    _transforms[i] = value[i];
                }
                _pdu.SetData("transforms", fieldPdus);
            }
        }
    }
}
