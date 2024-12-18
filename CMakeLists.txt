cmake_minimum_required(VERSION 3.19)

project(py-cpp)

set(CMAKE_CXX_STANDARD 11)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options(-g -O2 -Wall -Werror -Wno-unused)

include_directories(./)
include_directories(~/opt/anaconda3/include/python3.9/)

file(GLOB_RECURSE SOURCES "py/*.cpp")

link_directories(~/opt/anaconda3/lib/)
link_libraries(python3.9)

add_executable(test ${SOURCES} test.cpp)
add_executable(main ${SOURCES} main.cpp)
