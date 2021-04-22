//
// Created by lx on 2021/4/18.
//

#include "Log.h"
#include "DateTimeUtil.h"

const string Log::saveFile = "./log.txt";

void Log::info(const string & msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
}

void Log::info(const int &msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
}

void Log::info(const char &msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
}
