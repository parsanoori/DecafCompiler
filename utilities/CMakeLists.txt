project(utilities)

add_library(utilities src/dtype.cpp)

target_include_directories(utilities
        PUBLIC pubincl
)

