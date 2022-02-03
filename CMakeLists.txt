cmake_minimum_required(VERSION 3.0.2)

project(Compiler VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(preprocessor)

add_subdirectory(parser)

add_subdirectory(descriptor)

add_subdirectory(symboltable)

add_subdirectory(utilities)

add_subdirectory(semanticstack)

add_subdirectory(writer)

add_executable(compiler main.cpp)

target_link_libraries(compiler PUBLIC
        preprocessor parser descriptor
        utilities symboltable
        semanticstack writer
)
