project(descriptor)

add_library(descriptor src/descriptor.cpp)

#target_include_directories(descriptor
#    INTERFACE intrincl # descriptor
#)

target_include_directories(descriptor
    PRIVATE prvincl # id generator
)

target_include_directories(descriptor
    PUBLIC pubincl # type
)
