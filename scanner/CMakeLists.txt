add_library(scanner
src/lex.cpp
src/scanner.cpp)

execute_process (
    COMMAND bash -c "flex++ --outfile=src/lex.cpp lex.l"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


target_include_directories(scanner PUBLIC include)
