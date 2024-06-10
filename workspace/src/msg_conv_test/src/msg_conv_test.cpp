#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include <iostream>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include "can_msgs/pdu_ctype_conv_HakoCan.hpp"
#include "ev3_msgs/pdu_ctype_conv_EV3PduActuator.hpp"
#include "ev3_msgs/pdu_ctype_conv_EV3PduSensor.hpp"
#include "hako_msgs/pdu_ctype_conv_SimpleVarray.hpp"
#include "hako_msgs/pdu_ctype_conv_SimpleStructVarray.hpp"

using namespace std::chrono_literals;
#define HAKO_ASSERT(condition) \
    do { \
        if (!(condition)) { \
            std::cerr << "Assertion failed: (" #condition "), function " << __FUNCTION__ \
                      << ", file " << __FILE__ << ", line " << __LINE__ << ".\n" \
                      << std::endl; \
            std::exit(EXIT_FAILURE); \
        } \
        else { std::cout << "PASSED: " << #condition << std::endl; } \
    } while (false)
static void can_pdu2ros_test()
{
   printf("CAN*****\n");
   can_msgs::msg::HakoCan can_msg;
   Hako_HakoCan *can_pdu_ptr = hako_create_empty_pdu_HakoCan(0);
   HAKO_ASSERT(can_pdu_ptr != nullptr);
   Hako_HakoCan &can_pdu = *can_pdu_ptr;

   //prepare
   can_pdu.head.canid = 17;
   can_pdu.head.channel = 18;
   can_pdu.head.dlc = 19;
   can_pdu.head.ide = 20;
   can_pdu.head.rtr = 21;
   for (int i = 0; i < 8; i++) {
      can_pdu.body.data[i] = i + 10;
   }
 
   //do
   hako_convert_pdu2ros_HakoCan(can_pdu, can_msg);

   //done
   HAKO_ASSERT(can_msg.head.canid == 17);
   HAKO_ASSERT(can_msg.head.channel == 18);
   HAKO_ASSERT(can_msg.head.dlc == 19);
   HAKO_ASSERT(can_msg.head.ide == 20);
   HAKO_ASSERT(can_msg.head.rtr == 21);
   for (int i = 0; i < 8; i++) {
      HAKO_ASSERT(can_msg.body.data[i] == 10 + i);
   }
   hako_destroy_pdu(can_pdu_ptr);
   return;
}
#include <string.h>

static void ev3actuator_pdu2ros_test()
{
   printf("ACTUATOR*****\n");
   //prepare
   ev3_msgs::msg::Ev3PduActuator ev3_actuator_msg;
   Hako_Ev3PduActuator *ev3_actuator_pdu_ptr = hako_create_empty_pdu_Ev3PduActuator(0);
   HAKO_ASSERT(ev3_actuator_pdu_ptr != nullptr);
   Hako_Ev3PduActuator &ev3_actuator_pdu = *ev3_actuator_pdu_ptr;

   ev3_actuator_pdu.head.ext_off = 1;
   ev3_actuator_pdu.head.ext_size = 2;
   ev3_actuator_pdu.head.version = 3;
   ev3_actuator_pdu.head.asset_time = 4;
   memcpy(ev3_actuator_pdu.head.name, "TEST", 4);
   ev3_actuator_pdu.head.name[4] = '\0';
   ev3_actuator_pdu.leds[0] = 10;
   ev3_actuator_pdu.gyro_reset = 200;
   for (int i = 0; i < 3; i++) {
      ev3_actuator_pdu.motors[i].power = (i * 10) + 1;
      ev3_actuator_pdu.motors[i].stop = (i * 10) + 2;
      ev3_actuator_pdu.motors[i].reset_angle = (i * 10) + 3;
   }

   //do
   hako_convert_pdu2ros_Ev3PduActuator(ev3_actuator_pdu, ev3_actuator_msg);

   //done
   HAKO_ASSERT(ev3_actuator_msg.head.ext_off == 1);
   HAKO_ASSERT(ev3_actuator_msg.head.ext_size == 2);
   HAKO_ASSERT(ev3_actuator_msg.head.version == 3);
   HAKO_ASSERT(ev3_actuator_msg.head.asset_time == 4);
   HAKO_ASSERT(ev3_actuator_msg.head.name == "TEST");
   HAKO_ASSERT(ev3_actuator_msg.leds[0] == 10);
   HAKO_ASSERT(ev3_actuator_msg.gyro_reset == 200);
   for (unsigned int i = 0; i < 3; i++) {
      HAKO_ASSERT(ev3_actuator_msg.motors[i].power == (int)(i * 10) + 1);
      HAKO_ASSERT(ev3_actuator_msg.motors[i].stop == (i * 10) + 2);
      HAKO_ASSERT(ev3_actuator_msg.motors[i].reset_angle == (i * 10) + 3);
   }
   hako_destroy_pdu((void*)ev3_actuator_pdu_ptr);
}
static void ev3sensor_pdu2ros_test()
{
   printf("SENSOR*****\n");
   //prepare
   ev3_msgs::msg::Ev3PduSensor ev3_sensor_msg;
   Hako_Ev3PduSensor *ev3_sensor_pdu_ptr = hako_create_empty_pdu_Ev3PduSensor(0);
   HAKO_ASSERT(ev3_sensor_pdu_ptr != nullptr);
   Hako_Ev3PduSensor &ev3_sensor_pdu = *ev3_sensor_pdu_ptr;

   ev3_sensor_pdu.head.ext_off = 1;
   ev3_sensor_pdu.head.ext_size = 2;
   ev3_sensor_pdu.head.version = 3;
   ev3_sensor_pdu.head.hakoniwa_time = 4;
   memcpy(ev3_sensor_pdu.head.name, "SENSOR", 6);
   ev3_sensor_pdu.head.name[6] = '\0';
   ev3_sensor_pdu.buttons[0] = 10;
   ev3_sensor_pdu.gyro_degree = 11;
   ev3_sensor_pdu.gyro_degree_rate = 12;
   ev3_sensor_pdu.sensor_ultrasonic = 13;
   ev3_sensor_pdu.gps_lat = 14.1f;
   ev3_sensor_pdu.gps_lon = 15.5f;

   for (int i = 0; i < 2; i++) {
      ev3_sensor_pdu.color_sensors[i].color = (i * 10) + 1;
      ev3_sensor_pdu.color_sensors[i].reflect = (i * 10) + 2;
      ev3_sensor_pdu.color_sensors[i].rgb_r = (i * 10) + 3;
      ev3_sensor_pdu.color_sensors[i].rgb_g = (i * 10) + 4;
      ev3_sensor_pdu.color_sensors[i].rgb_b = (i * 10) + 5;
      ev3_sensor_pdu.touch_sensors[i].value = (i * 10) + 6;
   }
   for (int i = 0; i < 3; i++) {
      ev3_sensor_pdu.motor_angle[i] = (i * 10) + 7;
   }

   //do
   hako_convert_pdu2ros_Ev3PduSensor(ev3_sensor_pdu, ev3_sensor_msg);

   //done
   HAKO_ASSERT(ev3_sensor_msg.head.ext_off == 1);
   HAKO_ASSERT(ev3_sensor_msg.head.ext_size == 2);
   HAKO_ASSERT(ev3_sensor_msg.head.version == 3);
   HAKO_ASSERT(ev3_sensor_msg.head.hakoniwa_time == 4);
   HAKO_ASSERT(ev3_sensor_msg.head.name == "SENSOR");
   HAKO_ASSERT(ev3_sensor_msg.buttons[0] == 10);
   HAKO_ASSERT(ev3_sensor_msg.gyro_degree == 11);
   HAKO_ASSERT(ev3_sensor_msg.gyro_degree_rate == 12);
   HAKO_ASSERT(ev3_sensor_msg.sensor_ultrasonic == 13);
   //HAKO_ASSERT(ev3_sensor_msg.gps_lat == 14.1f);
   //HAKO_ASSERT(ev3_sensor_msg.gps_lon == 15.1f);
   std::cout << "gps_lat: " << ev3_sensor_msg.gps_lat << std::endl;
   std::cout << "gps_lon: " << ev3_sensor_msg.gps_lon << std::endl;

   for (unsigned int i = 0; i < 2; i++) {
      HAKO_ASSERT(ev3_sensor_msg.color_sensors[i].color == ((i * 10) + 1));
      HAKO_ASSERT(ev3_sensor_msg.color_sensors[i].reflect == ((i * 10) + 2));
      HAKO_ASSERT(ev3_sensor_msg.color_sensors[i].rgb_r == ((i * 10) + 3));
      HAKO_ASSERT(ev3_sensor_msg.color_sensors[i].rgb_g == ((i * 10) + 4));
      HAKO_ASSERT(ev3_sensor_msg.color_sensors[i].rgb_b == ((i * 10) + 5));
      HAKO_ASSERT(ev3_sensor_msg.touch_sensors[i].value == ((i * 10) + 6));
   }
   for (unsigned int i = 0; i < 3; i++) {
      HAKO_ASSERT(ev3_sensor_msg.motor_angle[i] == ((i * 10) + 7));
   }
   hako_destroy_pdu(ev3_sensor_pdu_ptr);
}


static void svarray_ros2pdu_test1()
{
   hako_msgs::msg::SimpleVarray src;

   src.p_mem1 = 324;
   src.fixed_array[0] = 1;
   src.fixed_array[1] = 2;
   src.data.resize(2);
   src.data[0] = 3;
   src.data[1] = 4;
   Hako_SimpleVarray *dst;
   hako_convert_ros2pdu_SimpleVarray(src, &dst);
   //std::cout << "len: " << len << std::endl;
   HAKO_ASSERT(dst->p_mem1 == src.p_mem1);
   HAKO_ASSERT(dst->fixed_array[0] == src.fixed_array[0]);
   HAKO_ASSERT(dst->fixed_array[1] == src.fixed_array[1]);
   HAKO_ASSERT(dst->_data_len == (int)src.data.size());
   //std::cout << "data_off: " << dst->_data_off << std::endl;

   hako_msgs::msg::SimpleVarray dst1;
   hako_convert_pdu2ros_SimpleVarray(*dst, dst1);
   //std::cout << "dst1.p_mem1: " << dst1.p_mem1 << std::endl;
   HAKO_ASSERT(dst1.p_mem1 == src.p_mem1);
   HAKO_ASSERT(dst1.fixed_array[0] == src.fixed_array[0]);
   HAKO_ASSERT(dst1.fixed_array[1] == src.fixed_array[1]);
   HAKO_ASSERT((int)dst1.data.size() == (int)src.data.size());
   HAKO_ASSERT(dst1.data[0] == 3);
   HAKO_ASSERT(dst1.data[1] == 4);
   hako_destroy_pdu(dst);
}

static void svarray_ros2pdu_test2()
{
   /*
typedef struct {
        Hako_int32 aaa;
        Hako_cstring fixed_str[2];
        // string varray_str[]
        int _varray_str_len;
        int _varray_str_off;
        Hako_SimpleVarray fixed_array[5];
        // SimpleVarray data[]
        int _data_len;
        int _data_off;
} Hako_SimpleStructVarray;   
   */
   hako_msgs::msg::SimpleStructVarray src;
   Hako_SimpleStructVarray *dst;
   src.aaa = 1;
   src.fixed_str[0] = "Takashi";
   src.fixed_str[1] = "Mori";
   src.varray_str.resize(1);
   src.varray_str[0] = "Takashi Mori";
   hako_msgs::msg::SimpleVarray child;
   for (int i = 0; i < 5; i++) {
      child.p_mem1 = 10 + i;
      child.fixed_array[0] = 10 + i;
      child.fixed_array[1] = 100 + i;
      src.fixed_array[i] = child;
   }
   src.data.resize(1);
   child.p_mem1 = 99;
   child.fixed_array[0] = 111;
   child.fixed_array[1] = 127;
   src.data[0] = child;
   hako_convert_ros2pdu_SimpleStructVarray(src, &dst);
   //std::cout << "len: " << len << std::endl;
   HAKO_ASSERT(dst->_varray_str_len == 1);
   HAKO_ASSERT(dst->_varray_str_off == 0);
   HAKO_ASSERT(dst->fixed_array[0].p_mem1 == 10);
   HAKO_ASSERT(dst->fixed_array[4].p_mem1 == 14);
   HAKO_ASSERT(dst->fixed_array[0].fixed_array[0] == 10);
   HAKO_ASSERT(dst->fixed_array[4].fixed_array[1] == 104);
   HAKO_ASSERT(dst->_data_len == 1);
   hako_msgs::msg::SimpleStructVarray dst1;
   hako_convert_pdu2ros_SimpleStructVarray(*dst, dst1);
   HAKO_ASSERT(dst1.aaa == 1);
   HAKO_ASSERT(dst1.fixed_str[0]  == "Takashi");
   HAKO_ASSERT(dst1.fixed_str[1]  == "Mori");
   HAKO_ASSERT(dst1.varray_str.size()  == 1);

   HAKO_ASSERT(dst1.varray_str[0]  == "Takashi Mori");
   HAKO_ASSERT(dst1.fixed_array[0].p_mem1 == 10);
   HAKO_ASSERT(dst1.fixed_array[4].p_mem1 == 14);
   HAKO_ASSERT(dst1.fixed_array[0].fixed_array[0] == 10);
   HAKO_ASSERT(dst1.fixed_array[4].fixed_array[1] == 104);
   //std::cout << "dst1.data.size(): " << dst1.data.size() << std::endl;
   //std::cout << "dst1.data[0].p_mem1: " << dst1.data[0].p_mem1 << std::endl;
   HAKO_ASSERT(dst1.data[0].p_mem1 == 99);
   HAKO_ASSERT(dst1.data[0].fixed_array[0] == 111);
   HAKO_ASSERT(dst1.data[0].fixed_array[1] == 127);
   hako_destroy_pdu(dst);

   std::cout << "PduMetaDataSize: " << HAKO_PDU_META_DATA_SIZE() << std::endl;
}

int main(int argc, char **argv) 
{
   rclcpp::init(argc, argv);
   can_pdu2ros_test();
   ev3actuator_pdu2ros_test();
   ev3sensor_pdu2ros_test();
   svarray_ros2pdu_test1();
   svarray_ros2pdu_test2();
   return 0;
}

