//
// Created by lx on 2021/4/18.
//

#include "DateTimeUtil.h"

string DateTimeUtil::nowDateTimeStr() {
    time_t now = time(0);
    struct tm t_struct;
    char buf[80];
    t_struct = *localtime(&now);

    strftime(buf, sizeof buf, "%Y-%m-%d.%X", &t_struct);

    return buf;
}
