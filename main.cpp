#include <iostream>

#include "systemc.h"
#include "bus/moudle/main_d.h"
#include "bus/moudle/second_d.h"
#include "bus/moudle/wishBound_bus_and_controller.h"

int sc_main(int, char **) {
    sc_clock clk("clk", 20, SC_NS);
    sc_signal<bool> rst{"rst"};
    sc_signal<bool> m_cyc_o{"signal_m_cyc_o"}, m_stb_o{"signal_m_stb_o"};
    sc_signal<bool> m_ack_i{"signal_m_ack_i"};
    sc_signal<sc_uint<32>> m_dat_i{"signal_m_dat_i"};
    sc_signal<sc_uint<32>> m_dat_o{"signal_m_dat_o"};
    sc_signal<sc_uint<8>> m_adr_o{"signal_m_adr_o"};
    sc_signal<bool> m_we_o{"signal_m_we_o"};
    sc_signal<sc_uint<4>> m_sel_o{"signal_m_sel_o"};
    sc_signal<bool> m_err_i{"signal_m_err_i"};
    sc_signal<bool> m_rty_i{"signal_m_rty_i"};

    sc_signal<bool> s_cyc_i{"signal_s_cyc_i"}, s_stb_i{"signal_s_stb_i"};
    sc_signal<bool> s_ack_o{"signal_s_ack_o"};
    sc_signal<sc_uint<32>> s_dat_i{"signal_s_dat_i"};
    sc_signal<sc_uint<32>> s_dat_o{"signal_s_dat_o"};
    sc_signal<sc_uint<8>> s_adr_i{"signal_s_adr_i"};
    sc_signal<bool> s_we_i{"signal_s_we_i"};
    sc_signal<sc_uint<4>> s_sel_i{"signal_s_sel_i"};
    sc_signal<bool> s_err_o{"signal_s_err_o"};
    sc_signal<bool> s_rty_o{"signal_s_rty_o"};

    // 连接信号
    main_d main_d_A("main_d_A");
    main_d_A.clk_i(clk);
    main_d_A.rst_i(rst);
    main_d_A.m_cyc_o(m_cyc_o);
    main_d_A.m_stb_o(m_stb_o);
    main_d_A.m_ack_i(m_ack_i);
    main_d_A.m_dat_i(m_dat_i);
    main_d_A.m_dat_o(m_dat_o);
    main_d_A.m_adr_o(m_adr_o);
    main_d_A.m_we_o(m_we_o);
    main_d_A.m_sel_o(m_sel_o);
    main_d_A.m_err_i(m_err_i);
    main_d_A.m_rty_i(m_rty_i);

    second_d second_d("second_d");
    second_d.rst_i(rst);
    second_d.clk_i(clk);
    second_d.s_cyc_i(s_cyc_i);
    second_d.s_stb_i(s_stb_i);
    second_d.s_ack_o(s_ack_o);
    second_d.s_dat_i(s_dat_i);
    second_d.s_dat_o(s_dat_o);
    second_d.s_adr_i(s_adr_i);
    second_d.s_we_i(s_we_i);
    second_d.s_sel_i(s_sel_i);
    second_d.s_err_o(s_err_o);
    second_d.s_rty_o(s_rty_o);

    wishBound_bus_and_controller bus("bus");
    bus.rst_i(rst);
    bus.clk_i(clk);
    bus.m_cyc_o(s_cyc_i);
    bus.m_stb_o(s_stb_i);
    bus.m_ack_i(s_ack_o);
    bus.m_dat_i(s_dat_o);
    bus.m_dat_o(s_dat_i);
    bus.m_adr_o(s_adr_i);
    bus.m_we_o(s_we_i);
    bus.m_sel_o(s_sel_i);
    bus.m_err_i(s_err_o);
    bus.m_rty_i(s_rty_o);
    bus.s_cyc_i(m_cyc_o);
    bus.s_stb_i(m_stb_o);
    bus.s_ack_o(m_ack_i);
    bus.s_dat_i(m_dat_o);
    bus.s_dat_o(m_dat_i);
    bus.s_adr_i(m_adr_o);
    bus.s_we_i(m_we_o);
    bus.s_sel_i(m_sel_o);
    bus.s_err_o(m_err_i);
    bus.s_rty_o(m_rty_i);

    // 捕捉信号
    sc_trace_file *tf = sc_create_vcd_trace_file("trace_bus.vcd");
    sc_trace(tf, bus.rst_i, "rst_i");
    sc_trace(tf, bus.clk_i, "clk_i");
    sc_trace(tf, bus.m_cyc_o, "m_cyc_o");
    sc_trace(tf, bus.m_stb_o, "m_stb_o");
    sc_trace(tf, bus.m_ack_i, "m_ack_i");
    sc_trace(tf, bus.m_dat_i, "m_dat_i");
    sc_trace(tf, bus.m_dat_o, "m_dat_o");
    sc_trace(tf, bus.m_adr_o, "m_adr_o");
    sc_trace(tf, bus.m_we_o, "m_we_o");
    sc_trace(tf, bus.m_sel_o, "m_sel_o");
    sc_trace(tf, bus.m_err_i, "m_err_i");
    sc_trace(tf, bus.m_rty_i, "m_rty_i");
    sc_trace(tf, bus.s_cyc_i, "s_cyc_i");
    sc_trace(tf, bus.s_stb_i, "s_stb_i");
    sc_trace(tf, bus.s_ack_o, "s_ack_o");
    sc_trace(tf, bus.s_dat_o, "s_dat_o");
    sc_trace(tf, bus.s_dat_i, "s_dat_i");
    sc_trace(tf, bus.s_adr_i, "s_adr_i");
    sc_trace(tf, bus.s_we_i, "s_we_i");
    sc_trace(tf, bus.s_sel_i, "s_sel_i");
    sc_trace(tf, bus.s_err_o, "s_err_o");
    sc_trace(tf, bus.s_rty_o, "s_rty_o");
    // 开始测试
    sc_start(2000, SC_NS);
    sc_close_vcd_trace_file(tf);

    return 0;
}