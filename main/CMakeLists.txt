# 主目录的CMakeLists.txt文件
# 
# 指定cmake最低版本
cmake_minimum_required(VERSION 3.15)

# 项目名称(只是一个名字而已)
project(XmlParser)

# 指定可执行文件的路径,PROJECT_SOURCE_DIR表示当前路径
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 如果不加下面两行，那么编译cmake时就要加参数-G “MinGW Makefiles” 用来指定编译器
# 通常需要加上，这样就可以直接在build目录下直接cmake .. 
# 描述有误，待验证
# 实际上应该是指定c语言文件和c++文件的默认编译器
# 如果win下环境变量里面没有设置mingw的路径的话，这里应该是可以帮助查找g++的路径
set(CMAKE_C_COMPILER "D:/Program Files/mingw64/bin/gcc.exe")
set(CMAKE_CXX_COMPILER "D:/Program Files/mingw64/bin/g++.exe")

# 添加了之后，就相当于在编译的时候加上了 -Wall -g选项
# -Wall : 编译时将错误信息打印出来
# -g : 启用gdb
add_definitions("-Wall -g")

# 查找当前目录下的所有源文件，.表示当前路径
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# include_directories
include_directories(../)

# 表示在指定目录查找指定库，，并把库的绝对路径存放到变量里
find_library(TESTFUNC_LIB testFunc HINTS ../lib)

# 指定生成目标
# xmlParser : 目标文件的名字
add_executable(xmlParser ${DIR_SRCS})

# 添加链接库
target_link_libraries(xmlParser ${TESTFUNC_LIB})

