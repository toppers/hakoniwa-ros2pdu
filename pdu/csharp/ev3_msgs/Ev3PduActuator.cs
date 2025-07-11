using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.ev3_msgs
{
    public class Ev3PduActuator
    {
        protected internal readonly IPdu _pdu;
        public IPdu GetPdu() { return _pdu; }

        public Ev3PduActuator(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Ev3PduActuatorHeader _head;
        public Ev3PduActuatorHeader head
        {
            get
            {
                if (_head == null)
                {
                    _head = new Ev3PduActuatorHeader(_pdu.GetData<IPdu>("head"));
                }
                return _head;
            }
            set
            {
                _head = value;
                _pdu.SetData("head", value.GetPdu());
            }
        }
        public byte[] leds
        {
            get => _pdu.GetDataArray<byte>("leds");
            set => _pdu.SetData("leds", value);
        }
        private Ev3PduMotor[] _motors;
        public Ev3PduMotor[] motors
        {
            get
            {
                if (_motors == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("motors");
                    _motors = new Ev3PduMotor[fieldPdus.Length];
                    Ev3PduMotor[] result = new Ev3PduMotor[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _motors[i] = new Ev3PduMotor(fieldPdus[i]);
                    }
                }
                return _motors;
            }
            set
            {
                _motors = new Ev3PduMotor[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i].GetPdu();
                    _motors[i] = value[i];
                }
                _pdu.SetData("motors", fieldPdus);
            }
        }
        public uint gyro_reset
        {
            get => _pdu.GetData<uint>("gyro_reset");
            set => _pdu.SetData("gyro_reset", value);
        }
    }
}
