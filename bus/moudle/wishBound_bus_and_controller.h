//
// Created by lx on 2021/4/18.
//

#ifndef WISHBOUND_WISHBOUND_BUS_AND_CONTROLLER_H
#define WISHBOUND_WISHBOUND_BUS_AND_CONTROLLER_H

#include "systemc.h"
#include "../transaction/bus_controller_if.h"

// 总线
class wishBound_bus_and_controller : public bus_controller_if, public sc_module{
public:
    sc_out<bool> m_cyc_o{"m_cyc_o"}, m_stb_o{"m_std_o"};      // 周期信号和选通信号
    sc_in<bool> m_ack_i{"m_ack_i"};                // 应答信号，表示成功
    sc_in<sc_uint<32>> m_dat_i{"m_dat_i"};         // 数据信号，占32位，接收数据的端口
    sc_out<sc_uint<32>> m_dat_o{"m_dat_o"};        // 数据信号，占32位，输出数据的端口
    sc_out<sc_uint<8>> m_adr_o{"m_adr_o"};         // 地址信号，8位，范围0-255，单位1字，4字节
    sc_out<bool> m_we_o{"m_we_o"};                // 写使能信号，1为写，0为读
    sc_out<sc_uint<4>> m_sel_o{"m_sel_o"};         // 有效数据总线选择信号，标识总线上数据信号中哪些字节有效
    sc_in<bool> m_err_i{"m_err_i"};                // 应答信号，表示错误
    sc_in<bool> m_rty_i{"m_rty_i"};                // 应答信号，表示重试

    sc_in<bool> s_cyc_i{"s_cyc_i"}, s_stb_i{"s_std_i"};
    sc_out<bool> s_ack_o{"s_ack_o"};
    sc_in<sc_uint<32>> s_dat_i{"s_dat_i"};
    sc_out<sc_uint<32>> s_dat_o{"s_dat_o"};
    sc_in<sc_uint<8>> s_adr_i{"s_adr_i"};
    sc_in<bool> s_we_i{"s_we_i"};
    sc_in<sc_uint<4>> s_sel_i{"s_sel_i"};
    sc_out<bool> s_err_o{"s_err_o"};
    sc_out<bool> s_rty_o{"s_rty_o"};

    sc_in<bool> rst_i{"bus_rst_i"};
    sc_in_clk clk_i{"bus_clk_i"};

    // 转发信号
    void tans_m_cyc_o();
    void tans_m_stb_o();
    void tans_s_ack_o();
    void tans_m_dat_o();
    void tans_s_dat_o();
    void tans_m_adr_o();
    void tans_m_we_o();
    void tans_m_sel_o();
    void tans_s_err_o();
    void tans_s_rty_o();

    SC_HAS_PROCESS(wishBound_bus_and_controller);
    wishBound_bus_and_controller(const sc_module_name &nm);
};


#endif //WISHBOUND_WISHBOUND_BUS_AND_CONTROLLER_H
