cmake_minimum_required(VERSION 3.10.2)
project(systemutils)

add_library(systemutils SHARED
    phoneinfo.cpp
    DeviceName.cpp
    CPUInfo.cpp
    GPUInfo.cpp
)

find_library(log-lib log)
find_library(GLESv2-lib GLESv2)

target_link_libraries(systemutils
    ${log-lib}
    ${GLESv2-lib}
)