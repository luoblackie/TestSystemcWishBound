//
// Created by lx on 2021/4/18.
//

#ifndef WISHBOUND_LOG_H
#define WISHBOUND_LOG_H

#include <iostream>
#include "systemc.h"

using namespace std;

class Log {
private:
    static const string saveFile;
public:
    static void info(const string & msg);
    static void info(const int & msg);
    static void info(const char & msg);
    static ofstream getSaveFileStream();
};


#endif //WISHBOUND_LOG_H
