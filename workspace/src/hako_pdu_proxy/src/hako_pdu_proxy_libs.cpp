#include "hako_pdu_proxy_libs.hpp"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

static void reset_callback();
static void start_callback();
static void stop_callback();
static void hako_asset_signal_handler(int sig);

static std::string *hako_asset_name = nullptr;
static bool hako_asset_is_end = false;
static HakoTimeType hako_asset_time_usec = 0LL;
static std::shared_ptr<hako::IHakoSimulationEventController> hako_sim_ctrl = nullptr;
static std::shared_ptr<hako::IHakoAssetController> hako_asset = nullptr;
static HakoTimeType hako_delta_usec = 1000;

bool hako_pdu_proxy_init(const char *asset_name, HakoTimeType delta_usec)
{
    hako_delta_usec = delta_usec;

    //signal(SIGINT, hako_asset_signal_handler);
    //signal(SIGTERM, hako_asset_signal_handler);

    hako_asset_name = new std::string(asset_name);

    //hako::logger::init("core");
    hako_asset = hako::create_asset_controller();
    if (hako_asset == nullptr) {
        std::cout << "ERROR: Not found hako-master on this PC" << std::endl;
        return false;
    }
    AssetCallbackType callback;
    callback.reset = reset_callback;
    callback.start = start_callback;
    callback.stop = stop_callback;
    bool ret = hako_asset->asset_register(*hako_asset_name, callback);
    if (ret == false) {
        std::cout << "ERROR: Can not register asset" << std::endl;
        return false;
    }
    return true;
}

bool hako_pdu_proxy_run(bool &can_step)
{
    can_step = false;
    if (hako_asset->is_pdu_created() == false) {
        //std::cout << "not pdu created...yet" << std::endl;
    }
    else if (hako_asset->is_simulation_mode()) {
        hako_asset->notify_simtime(*hako_asset_name, hako_asset_time_usec);
        HakoTimeType world_time = hako_asset->get_worldtime();
        if (world_time >= hako_asset_time_usec) {
            hako_asset_time_usec += hako_delta_usec;
            can_step = true;
            //std::cout << "TIME: " << hako_asset_time_usec << std::endl;
        }
    }
    else if (hako_asset->is_pdu_sync_mode(*hako_asset_name)) {
        hako_asset->notify_write_pdu_done(*hako_asset_name);
        //std::cout << "WRITE PDU_DONE " << std::endl;
    }
    else {
        //std::cout << "WHAT?? " << hako_asset_is_end << std::endl;
    }
    return (hako_asset_is_end == false);
}

void hako_pdu_proxy_fin()
{
    hako_asset->asset_unregister(*hako_asset_name);
    //hako::logger::get("core")->flush();
    return;
}
static void reset_callback()
{
    hako_asset_time_usec = 0;
    hako_asset->reset_feedback(*hako_asset_name, true);
}
static void start_callback()
{
    hako_asset->start_feedback(*hako_asset_name, true);
}
static void stop_callback()
{
    hako_asset->stop_feedback(*hako_asset_name, true);
}

static void hako_asset_signal_handler(int sig)
{
    if (sig > 0) {
        //NOP
    }
    if (hako_asset_name != nullptr) {
        //hako::logger::get(*hako_asset_name)->info("SIGNAL RECV: {0}", sig);
    }
    hako_asset_is_end = true;
}


bool hako_pdu_proxy_rx_data(const std::string& robo_name, HakoPduChannelIdType pdu_channel, char* pdu_msg, int buflen)
{
    if (hako_asset->is_pdu_created() == false) {
        return false;
    }
    else if (hako_asset->is_simulation_mode()) {
       if (hako_asset->is_pdu_dirty(*hako_asset_name, robo_name, pdu_channel)) {
           bool ret = hako_asset->read_pdu(*hako_asset_name, robo_name, pdu_channel, pdu_msg, buflen);
           hako_asset->notify_read_pdu_done(*hako_asset_name);
           return ret;
       }
    }
    return false;
}
bool hako_pdu_proxy_tx_init(const std::string& robo_name, HakoPduChannelIdType pdu_channel, int buflen)
{
    return hako_asset->create_pdu_lchannel(robo_name, pdu_channel, buflen);
}
bool hako_pdu_proxy_tx_data(const std::string& robo_name, HakoPduChannelIdType pdu_channel, char* pdu_msg, int buflen)
{
    if (hako_asset->is_pdu_created() == false) {
        return false;
    }
    else if (hako_asset->is_simulation_mode())
    {
        //printf("write_pdu\n");
        return hako_asset->write_pdu(*hako_asset_name, robo_name, pdu_channel, pdu_msg, buflen);
    }
    return false;
}
