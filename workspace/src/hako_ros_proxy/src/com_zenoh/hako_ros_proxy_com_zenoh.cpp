#include "hako_ros_proxy_com_zenoh.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

HakoZenohSessionType hako_ros_proxy_zenoh_session;

bool hako_ros_proxy_zenoh_initialize()
{
    z_owned_config_t config = z_config_default();
    std::cout << "INFO: Zenoh Opening session..." << std::endl;
    hako_ros_proxy_zenoh_session.s = z_open(z_move(config));
    if (!z_check(hako_ros_proxy_zenoh_session.s)) {
        std::cerr << "ERROR: Zenoh Unable to open session!" << std::endl;
        return false;
    }
    return true;
}

void hako_ros_proxy_zenoh_finalize()
{
    z_close(z_move(hako_ros_proxy_zenoh_session.s));
}
