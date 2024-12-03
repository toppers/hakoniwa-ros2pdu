using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using hakoniwa.pdu.interfaces;

namespace hakoniwa.pdu.msgs.ev3_msgs
{
    public class Ev3PduSensor
    {
        protected internal readonly IPdu _pdu;

        public Ev3PduSensor(IPdu pdu)
        {
            _pdu = pdu;
        }
        private Ev3PduSensorHeader _head;
        public Ev3PduSensorHeader head
        {
            get
            {
                if (_head == null)
                {
                    _head = new Ev3PduSensorHeader(_pdu.GetData<IPdu>("head"));
                }
                return _head;
            }
            set
            {
                _head = value;
                _pdu.SetData("head", value._pdu);
            }
        }
        public byte[] buttons
        {
            get => _pdu.GetDataArray<byte>("buttons");
            set => _pdu.SetData("buttons", value);
        }
        private Ev3PduColorSensor[] _color_sensors;
        public Ev3PduColorSensor[] color_sensors
        {
            get
            {
                if (_color_sensors == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("color_sensors");
                    _color_sensors = new Ev3PduColorSensor[fieldPdus.Length];
                    Ev3PduColorSensor[] result = new Ev3PduColorSensor[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _color_sensors[i] = new Ev3PduColorSensor(fieldPdus[i]);
                    }
                }
                return _color_sensors;
            }
            set
            {
                _color_sensors = new Ev3PduColorSensor[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i]._pdu;
                    _color_sensors[i] = value[i];
                }
                _pdu.SetData("color_sensors", fieldPdus);
            }
        }
        private Ev3PduTouchSensor[] _touch_sensors;
        public Ev3PduTouchSensor[] touch_sensors
        {
            get
            {
                if (_touch_sensors == null)
                {
                    var fieldPdus = _pdu.GetDataArray<IPdu>("touch_sensors");
                    _touch_sensors = new Ev3PduTouchSensor[fieldPdus.Length];
                    Ev3PduTouchSensor[] result = new Ev3PduTouchSensor[fieldPdus.Length];
                    for (int i = 0; i < fieldPdus.Length; i++)
                    {
                        _touch_sensors[i] = new Ev3PduTouchSensor(fieldPdus[i]);
                    }
                }
                return _touch_sensors;
            }
            set
            {
                _touch_sensors = new Ev3PduTouchSensor[value.Length];
                IPdu[] fieldPdus = new IPdu[value.Length];
                for (int i = 0; i < value.Length; i++)
                {
                    fieldPdus[i] = value[i]._pdu;
                    _touch_sensors[i] = value[i];
                }
                _pdu.SetData("touch_sensors", fieldPdus);
            }
        }
        public uint[] motor_angle
        {
            get => _pdu.GetDataArray<uint>("motor_angle");
            set => _pdu.SetData("motor_angle", value);
        }
        public int gyro_degree
        {
            get => _pdu.GetData<int>("gyro_degree");
            set => _pdu.SetData("gyro_degree", value);
        }
        public int gyro_degree_rate
        {
            get => _pdu.GetData<int>("gyro_degree_rate");
            set => _pdu.SetData("gyro_degree_rate", value);
        }
        public uint sensor_ultrasonic
        {
            get => _pdu.GetData<uint>("sensor_ultrasonic");
            set => _pdu.SetData("sensor_ultrasonic", value);
        }
        public double gps_lat
        {
            get => _pdu.GetData<double>("gps_lat");
            set => _pdu.SetData("gps_lat", value);
        }
        public double gps_lon
        {
            get => _pdu.GetData<double>("gps_lon");
            set => _pdu.SetData("gps_lon", value);
        }
    }
}
