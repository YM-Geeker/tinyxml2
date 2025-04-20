cmake_minimum_required(VERSION 3.15)
project(tinyxml2 VERSION 11.0.0)

set(CMAKE_C_COMPILER "D:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Program Files/mingw64/bin/g++.exe")

set (SRC_LIST ./tinyxml2.cpp ./tinyxml2.h)

# add_libary -- 增加库文件；SHARED -- 动态库
# add_library (testFunc_shared SHARED ${SRC_LIST})

# STATIC -- 静态库文件；
add_library (testFunc_static STATIC ${SRC_LIST})

# set_target_properties (testFunc_shared PROPERTIES OUTPUT_NAME "testFunc")
set_target_properties (testFunc_static PROPERTIES OUTPUT_NAME "testFunc")

set (LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
