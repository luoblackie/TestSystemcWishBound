//
// Created by lx on 2021/4/18.
//

#include "main_d.h"
#include "../../util/Log.h"

using namespace std;

void main_d::read(sc_uint<8> adr, int &data) {
    Log::info("主设备：读操作开始。。。data = ");
    Log::info(data);
    wait(clk_i.posedge_event());
    m_adr_o = adr;
    m_we_o = false;
    m_sel_o = 0b1111;
    m_stb_o = m_cyc_o = true;

    // 等待从设备应答
    do{
        wait(clk_i.posedge_event());
    } while (!m_ack_i);

    // 读总线数据
    data = m_dat_i.read();
    m_cyc_o = m_stb_o = false;
    Log::info("主设备：读操作结束。。。");
}

void main_d::write(sc_uint<8> adr, int data) {
    Log::info("主设备写操作开始...data = ");
    Log::info(data);
    // 等时钟上升沿
    wait(clk_i.posedge_event());
    m_adr_o = adr;
    m_dat_o = data;
    m_we_o = true;
    m_sel_o = 0b1111;
    m_cyc_o = m_stb_o = true;

    // 等待应答
    do{
        wait(clk_i.posedge_event());
    } while (!m_ack_i);

    // 结束本次操作
    m_cyc_o = m_stb_o = false;
    Log::info("主设备写操作结束。。。");
}

void main_d::do_test() {
    Log::info("主设备模拟事务");
    string str = "hello, systemc!";
    // 测试写
    for(int i=0; i<str.length(); ++i){
        write(i, str[i]);
    }

    // 测试读
    int buf[40];
    for(int i=0; i<str.length(); ++i){
        read(i, buf[i]);
    }
    Log::info("主设备：从设备中取出的数据：");
    for(int i=0; i<str.length(); ++i)
        cout<<(char)buf[i];
    cout<<endl;

    // 输出到日志
    ofstream file = Log::getSaveFileStream();
    for(int i=0; i<str.length(); ++i)
        file<<(char)buf[i];
    file<<"\n";
    file.close();
}

main_d::main_d(const sc_module_name &nm) : sc_module(nm) {
    Log::info("主设备创建");
    SC_THREAD(do_test);
    sensitive<<clk_i.pos();
}



