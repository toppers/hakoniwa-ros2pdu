#include <stdio.h>

#include "pdu_primitive_ctypes.h"
#include <iostream>
#include <string.h>
#include "rclcpp/rclcpp.hpp"
#include "can_msgs/pdu_ctype_conv_HakoCan.hpp"
#include "ev3_msgs/pdu_ctype_conv_EV3PduActuator.hpp"
#include "ev3_msgs/pdu_ctype_conv_EV3PduSensor.hpp"

using namespace std::chrono_literals;

static void can_pdu2ros_test()
{
   printf("CAN*****\n");
    can_msgs::msg::HakoCan can_msg;
    Hako_HakoCan can_pdu;

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
    std::cout << "canid=" << can_msg.head.canid << std::endl;
    std::cout << "channel=" << can_msg.head.channel << std::endl;
    std::cout << "dlc=" << can_msg.head.dlc << std::endl;
    std::cout << "ide=" << can_msg.head.ide << std::endl;
    std::cout << "rtr=" << can_msg.head.rtr << std::endl;
    for (int i = 0; i < 8; i++) {
       printf("data=%d\n", can_msg.body.data[i]);
    }
    return;
}
#include <string.h>

static void ev3actuator_pdu2ros_test()
{
   printf("ACTUATOR*****\n");
   //prepare
   ev3_msgs::msg::Ev3PduActuator ev3_actuator_msg;
   Hako_Ev3PduActuator ev3_actuator_pdu;

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
   std::cout << "ext_off=" << ev3_actuator_msg.head.ext_off << std::endl;
   std::cout << "ext_size=" << ev3_actuator_msg.head.ext_size << std::endl;
   std::cout << "version=" << ev3_actuator_msg.head.version << std::endl;
   std::cout << "asset_time=" << ev3_actuator_msg.head.asset_time << std::endl;
   std::cout << "name=" << ev3_actuator_msg.head.name << std::endl;
   printf("leds=%d\n", ev3_actuator_msg.leds[0]);
   std::cout << "gyro_reset=" << ev3_actuator_msg.gyro_reset << std::endl;
   for (int i = 0; i < 3; i++) {
      printf("motoros[%d].power=%d\n", i, ev3_actuator_msg.motors[i].power);
      printf("motoros[%d].stop=%d\n", i, ev3_actuator_msg.motors[i].stop);
      printf("motoros[%d].reset_angle=%d\n", i, ev3_actuator_msg.motors[i].reset_angle);
   }

}
static void ev3sensor_pdu2ros_test()
{
   printf("SENSOR*****\n");
   //prepare
   ev3_msgs::msg::Ev3PduSensor ev3_sensor_msg;
   Hako_Ev3PduSensor ev3_sensor_pdu;

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
   std::cout << "ext_off=" << ev3_sensor_msg.head.ext_off << std::endl;
   std::cout << "ext_size=" << ev3_sensor_msg.head.ext_size << std::endl;
   std::cout << "version=" << ev3_sensor_msg.head.version << std::endl;
   std::cout << "hakoniwa_time=" << ev3_sensor_msg.head.hakoniwa_time << std::endl;
   std::cout << "name=" << ev3_sensor_msg.head.name << std::endl;
   printf("buttons=%d\n", ev3_sensor_msg.buttons[0]);
   std::cout << "gyro_degree=" << ev3_sensor_msg.gyro_degree << std::endl;
   std::cout << "gyro_degree_rate=" << ev3_sensor_msg.gyro_degree_rate << std::endl;
   std::cout << "sensor_ultrasonic=" << ev3_sensor_msg.sensor_ultrasonic << std::endl;
   std::cout << "gps_lat=" << ev3_sensor_msg.gps_lat << std::endl;
   std::cout << "gps_lon=" << ev3_sensor_msg.gps_lon << std::endl;
   for (int i = 0; i < 2; i++) {
      printf("color_sensors[%d].color=%d\n", i, ev3_sensor_msg.color_sensors[i].color);
      printf("color_sensors[%d].reflect=%d\n", i, ev3_sensor_msg.color_sensors[i].reflect);
      printf("color_sensors[%d].rgb_r=%d\n", i, ev3_sensor_msg.color_sensors[i].rgb_r);
      printf("color_sensors[%d].rgb_g=%d\n", i, ev3_sensor_msg.color_sensors[i].rgb_g);
      printf("color_sensors[%d].rgb_b=%d\n", i, ev3_sensor_msg.color_sensors[i].rgb_b);
      printf("touch_sensors[%d].value=%d\n", i, ev3_sensor_msg.touch_sensors[i].value);
   }
   for (int i = 0; i < 3; i++) {
      printf("motor_angle[%d]=%d\n", i, ev3_sensor_msg.motor_angle[i]);
   }
}
int main(int argc, char **argv) 
{
   rclcpp::init(argc, argv);
   can_pdu2ros_test();
   ev3actuator_pdu2ros_test();
   ev3sensor_pdu2ros_test();

   return 0;
}

