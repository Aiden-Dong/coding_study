# cmake 版本
cmake_minimum_required(VERSION 3.13.2)

# project : 工程名称
project(cmake_study)

# 添加版本号
set(cmake_study_VERSION_MAJOR 1)
set(cmake_study_VERSION_MANOR 0)

set(CMAKE_CXX_STANDARD 11)

# 查找目录下所有的源文件
aux_source_directory(src/persion PERSION)

# 编译
add_library(persion ${PERSION} src/persion/address.h)

# 添加执行
add_executable(cmake_study src/main.cpp)

# 链接静态库
target_link_libraries(cmake_study persion)