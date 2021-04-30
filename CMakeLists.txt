cmake_minimum_required(VERSION 3.19)
project(LearnCpp)

set(CMAKE_CXX_STANDARD 14)

add_executable(LearnCpp main.cpp entities/Entity.cpp entities/Entity.h entities/Player.cpp entities/Player.h)

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
