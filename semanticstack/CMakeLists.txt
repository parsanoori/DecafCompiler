project(semanticstack)

add_library(semanticstack INTERFACE)

target_include_directories(semanticstack
        INTERFACE pubincl
)

target_link_libraries(semanticstack
        INTERFACE semanticstack
)