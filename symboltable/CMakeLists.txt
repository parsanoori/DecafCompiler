project(symboltable)

add_library(symboltable src/symboltable.cpp
)

target_link_libraries(symboltable
    descriptor
)

target_include_directories(symboltable
    PUBLIC prvincl
)

target_include_directories(symboltable
    PUBLIC pubincl
)

