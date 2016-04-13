cmake_minimum_required(VERSION 3.5)
project(project_technosphere_c_master_v2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp case.cpp case.h cost.cpp cost.h date.cpp date.h enums.h day.cpp day.h)
add_executable(project_technosphere_c_master_v2 ${SOURCE_FILES})