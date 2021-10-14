add_library(scanner
src/lex.cpp
src/scanner.cpp)

#add_custom_command ( OUTPUT src/lexer.cpp
#                     COMMAND flex++ --outfile=src/lex.cpp lex.l  && echo "slm"
#                     WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/)

execute_process (
    COMMAND bash -c "flex++ --outfile=src/lex.cpp lex.l"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)


target_include_directories(scanner PUBLIC include)
