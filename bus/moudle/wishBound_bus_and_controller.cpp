//
// Created by lx on 2021/4/18.
//

#include "wishBound_bus_and_controller.h"
#include "../../util/Log.h"


wishBound_bus_and_controller::wishBound_bus_and_controller(const sc_module_name &nm) : sc_module(nm) {
    Log::info("总线创建");

    // 总线信号转发
    SC_METHOD(tans_m_cyc_o);
    sensitive<<s_cyc_i;
    SC_METHOD(tans_m_stb_o);
    sensitive<<s_stb_i;
    SC_METHOD(tans_s_ack_o);
    sensitive<<m_ack_i;
    SC_METHOD(tans_m_dat_o);
    sensitive<<s_dat_i;
    SC_METHOD(tans_s_dat_o);
    sensitive<<m_dat_i;
    SC_METHOD(tans_m_adr_o);
    sensitive<<s_adr_i;
    SC_METHOD(tans_m_we_o);
    sensitive<<s_we_i;
    SC_METHOD(tans_m_sel_o);
    sensitive<<s_sel_i;
    SC_METHOD(tans_s_err_o);
    sensitive<<m_err_i;
    SC_METHOD(tans_s_rty_o);
    sensitive<<m_rty_i;

}

void wishBound_bus_and_controller::tans_m_stb_o() {
    m_stb_o = s_stb_i;
}

void wishBound_bus_and_controller::tans_m_cyc_o() {
    m_cyc_o = s_cyc_i;
}

void wishBound_bus_and_controller::tans_s_ack_o() {
    s_ack_o = m_ack_i;
}

void wishBound_bus_and_controller::tans_m_dat_o() {
    m_dat_o = s_dat_i;
}

void wishBound_bus_and_controller::tans_s_dat_o() {
    s_dat_o = m_dat_i;
}

void wishBound_bus_and_controller::tans_m_adr_o() {
    m_adr_o = s_adr_i;
}

void wishBound_bus_and_controller::tans_m_we_o() {
    m_we_o = s_we_i;
}

void wishBound_bus_and_controller::tans_m_sel_o() {
    m_sel_o = s_sel_i;
}

void wishBound_bus_and_controller::tans_s_err_o() {
    s_err_o = m_err_i;
}

void wishBound_bus_and_controller::tans_s_rty_o() {
    s_rty_o = m_rty_i;
}
