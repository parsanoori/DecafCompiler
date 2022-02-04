project(codegen)

add_library(codegen src/codegen.cpp)

target_include_directories(codegen
        PUBLIC pubincl
)

target_link_libraries(codegen
        PUBLIC writer semanticstack
        symboltable descriptor utilities
        functiontable
)
