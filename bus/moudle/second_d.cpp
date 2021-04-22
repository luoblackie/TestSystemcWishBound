//
// Created by lx on 2021/4/18.
//

#include "second_d.h"
#include "../../util/Log.h"

void second_d::do_respond() {
    // 操作开始
    if(s_stb_i == true){
        // 读操作
        if(s_we_i == false){
            Log::info("从设备：应答读操作。。。");
            s_dat_o = dataMatrix[s_adr_i.read()];
            s_ack_o = true;
        }

        // 写操作
        if(s_we_i == true){
            Log::info("从设备：应答写操作。。。");
            s_ack_o = true;
            // 等待时钟上升沿，写入数据到存储体中
            next_trigger(clk_i.posedge_event());
            dataMatrix[s_adr_i.read()] = s_dat_i.read();
        }
    }

    // 操作结束
    if(s_stb_i == false){
        Log::info("从设备：检测到选通信号为低电平，置ack为低电平。。。");
        s_ack_o = false;
    }
}

second_d::second_d(const sc_module_name &nm) : sc_module(nm) {
    Log::info("从设备创建");
    SC_METHOD(do_respond);
    sensitive<<s_stb_i<<clk_i.pos();
}


