//
// Created by lx on 2021/4/18.
//

#ifndef WISHBOUND_INTERFACE_BUS_TRANSACTION_H
#define WISHBOUND_INTERFACE_BUS_TRANSACTION_H

#include "systemc.h"

class bus_if: public sc_interface {
public:
    // 总线的读操作，每次只读32位，一字
    virtual void read(sc_uint<8> adr, int &data) = 0;
    // 总线的写操作，每次只写32位，一字
    virtual void write(sc_uint<8> adr, int data) = 0;
};


#endif //WISHBOUND_INTERFACE_BUS_TRANSACTION_H
