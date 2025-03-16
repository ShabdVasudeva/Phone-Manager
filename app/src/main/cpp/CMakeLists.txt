cmake_minimum_required(VERSION 3.10.2)
project(systemutils)

# Add all source files
add_library(systemutils SHARED
    phoneinfo.cpp
    DeviceName.cpp
    CPUInfo.cpp
)

# Find required libraries
find_library(log-lib log)
find_library(GLESv2-lib GLESv2)  # Find OpenGL ES library

# Link libraries to your native library
target_link_libraries(systemutils
    ${log-lib}
    ${GLESv2-lib}  # Link OpenGL ES to resolve glGetString
)