cmake_minimum_required(VERSION 3.13)
project(cpp_primer_study)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(src/class VCLASS)
include_directories(src/class VHEAD)

add_library(vclass ${VCLASS} ${VHEAD})
add_library(main src/main.cpp)

target_link_libraries(vclass main)

add_executable(cpp_primer_study src/main.cpp)