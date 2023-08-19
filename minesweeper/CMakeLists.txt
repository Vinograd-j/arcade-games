add_library(minesweeper STATIC
        src/game.cpp)

target_link_libraries(minesweeper PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main)
target_include_directories(minesweeper PRIVATE include)