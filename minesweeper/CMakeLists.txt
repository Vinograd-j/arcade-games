add_library(minesweeper STATIC
        src/main-menu.cpp)

target_link_libraries(minesweeper PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main)
target_include_directories(minesweeper PRIVATE include)