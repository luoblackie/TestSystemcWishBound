//
// Created by lx on 2021/4/18.
//

#include "Log.h"
#include "DateTimeUtil.h"
#include <fstream>

const string Log::saveFile = "./log.txt";

void Log::info(const string & msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
    ofstream file(saveFile, ios::app);
    file<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<"\n";
    file.close();
}

void Log::info(const int &msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
    ofstream file(saveFile, ios::app);
    file<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<"\n";
    file.close();
}

void Log::info(const char &msg) {
    cout<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<endl;
    ofstream file(saveFile, ios::app);
    file<<"[ "<<DateTimeUtil::nowDateTimeStr()<<" ][ "<<sc_time_stamp()<<" ] "<<msg<<"\n";
    file.close();
}

ofstream Log::getSaveFileStream() {
    ofstream file(saveFile, ios::app);
    return file;
}
