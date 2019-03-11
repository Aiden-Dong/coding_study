cmake_minimum_required(VERSION 3.13)
project(cpp_primer_study)

set(CMAKE_CXX_STANDARD 11)

# 全局变量：CMAKE_SOURCE_DIR CMake的起始目录，即源码的根目录
# 全局变量：PROJECT_NAME 工程的名称
# 全局变量：PROJECT_SOURCE_DIR 工程的源码根目录的完整路径

# 全局变量：构建输出目录。默认的，对于内部构建，此变量的值等于CMAKE_SOURCE_DIR；否则等于构建树的根目录

# 全局变量：构建输出目录。默认的，对于内部构建，此变量的值等于CMAKE_SOURCE_DIR；否则等于构建树的根目录
#set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build/target)  # ${}语法用于引用变量
## 全局变量：可执行文件的输出路径
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
## 全局变量：库文件的输出路径
#set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
#
## 链接本地库
aux_source_directory(src/process VCLASS)
add_library(vclass ${VCLASS})


# 链接第三方库
#include_directories(/usr/local/Cellar/log4cxx/0.10.0_1/include)
#link_directories(/usr/local/Cellar/log4cxx/0.10.0_1/lib)
#link_libraries(log4cxx)

# 资源文件
#configure_file(conf/log4cxx.properties ${CMAKE_BINARY_DIR}/conf/log4cxx.properties)

add_executable(cpp_primer_study main.cpp)
target_link_libraries(cpp_primer_study vclass)



