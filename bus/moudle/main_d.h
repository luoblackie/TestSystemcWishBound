//
// Created by lx on 2021/4/18.
//

#ifndef WISHBOUND_MAIN_D_H
#define WISHBOUND_MAIN_D_H

#include "systemc.h"
#include "../transaction/bus_if.h"

class main_d : public bus_if, public sc_module {
public:
    sc_in<bool> rst_i{"m_rst_i"};                  // 同步复位信号
    sc_in_clk clk_i{"m_clk_i"};                    // 时钟信号
    sc_out<bool> m_cyc_o{"m_cyc_o"}, m_stb_o{"m_std_o"};      // 周期信号和选通信号
    sc_in<bool> m_ack_i{"m_ack_i"};                // 应答信号，表示成功
    sc_in<sc_uint<32>> m_dat_i{"m_dat_i"};         // 数据信号，占32位，接收数据的端口
    sc_out<sc_uint<32>> m_dat_o{"m_dat_o"};        // 数据信号，占32位，输出数据的端口
    sc_out<sc_uint<8>> m_adr_o{"m_adr_o"};         // 地址信号，8位，范围0-255，单位1字，4字节
    sc_out<bool> m_we_o{"m_we_o"};                // 写使能信号，1为写，0为读
    sc_out<sc_uint<4>> m_sel_o{"m_sel_o"};         // 有效数据总线选择信号，标识总线上数据信号中哪些字节有效
    sc_in<bool> m_err_i{"m_err_i"};                // 应答信号，表示错误
    sc_in<bool> m_rty_i{"m_rty_i"};                // 应答信号，表示重试

    void read(sc_uint<8> adr, int &data) override;
    void write(sc_uint<8> adr, int data) override;

    void do_test();

    SC_HAS_PROCESS(main_d);

    main_d(const sc_module_name &nm);
};


#endif //WISHBOUND_MAIN_D_H
