//
// Created by lx on 2021/4/18.
//

#ifndef WISHBOUND_SECOND_D_H
#define WISHBOUND_SECOND_D_H

#include "systemc.h"

class second_d : public sc_module{
private:
    int dataMatrix[256];
    bool busy = false;
public:
    sc_in<bool> rst_i{"s_rst_i"};
    sc_in_clk clk_i{"s_clk_i"};
    sc_in<bool> s_cyc_i{"s_cyc_i"}, s_stb_i{"s_std_i"};
    sc_out<bool> s_ack_o{"s_ack_o"};
    sc_in<sc_uint<32>> s_dat_i{"s_dat_i"};
    sc_out<sc_uint<32>> s_dat_o{"s_dat_o"};
    sc_in<sc_uint<8>> s_adr_i{"s_adr_i"};
    sc_in<bool> s_we_i{"s_we_i"};
    sc_in<sc_uint<4>> s_sel_i{"s_sel_i"};
    sc_out<bool> s_err_o{"s_err_o"};
    sc_out<bool> s_rty_o{"s_rty_o"};

    void do_respond();

    SC_HAS_PROCESS(second_d);

    second_d(const sc_module_name &nm);
};


#endif //WISHBOUND_SECOND_D_H
