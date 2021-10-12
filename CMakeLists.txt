cmake_minimum_required(VERSION 3.21)

project(Compiler VERSION 0.0.1)

add_subdirectory(preprocessor)

add_executable(compiler main.cpp)

target_link_libraries(compiler PUBLIC preprocessor) 


