project(functiontable)

add_library(functiontable
        src/functiontable.cpp
)

target_include_directories(functiontable
        PUBLIC pubincl
)

target_link_libraries(functiontable
        utilities
)