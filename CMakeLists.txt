cmake_minimum_required(VERSION 3.17)
project(testSystemc)

include_directories(/usr/local/systemc-2.3.3/include)
link_directories(/usr/local/systemc-2.3.3/lib-linux64/libsystemc.so)
link_libraries(/usr/local/systemc-2.3.3/lib-linux64/libsystemc.a)

ADD_DEFINITIONS(-DSC_DISABLE_API_VERSION_CHECK)

set(CMAKE_CXX_STANDARD 11)

add_executable(wishBound main.cpp bus/transaction/bus_if.h bus/transaction/bus_controller_if.h bus/moudle/main_d.cpp bus/moudle/main_d.h bus/moudle/second_d.cpp bus/moudle/second_d.h bus/moudle/wishBound_bus_and_controller.cpp bus/moudle/wishBound_bus_and_controller.h util/Log.cpp util/Log.h util/DateTimeUtil.cpp util/DateTimeUtil.h)