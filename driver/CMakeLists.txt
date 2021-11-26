add_library(driver src/driver.cc src/parser.cc src/scanner.cc)

execute_process(COMMAND bash -c "bison --html --graph -o src/parser.cc parser.yy  && 
    mv src/location.hh include/location.hh &&
    mv src/parser.hh include/parser.hh &&
    mv src/parser.html parser_outs &&
    mv src/parser.gv parser_outs &&
    mv src/parser.xml parser_outs &&
    flex -o src/scanner.cc scanner.ll"
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)

target_include_directories(driver PUBLIC include)
