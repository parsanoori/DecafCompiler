project(writer)

add_library(writer
        src/writer.cpp
)

target_include_directories(writer
        PUBLIC pubincl
)