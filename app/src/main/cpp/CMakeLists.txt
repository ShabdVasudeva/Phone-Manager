cmake_minimum_required(VERSION 3.10.2)
project(systemutils)

# Add all source files
add_library(systemutils SHARED
    phoneinfo.cpp
    DeviceName.cpp
    CPUInfo.cpp
)

find_library(log-lib log)
target_link_libraries(systemutils ${log-lib})