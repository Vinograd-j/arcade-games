add_library(minesweeper STATIC
            src/cell.cpp
        src/level.cpp
            src/level-window.cpp include/easy-level.h include/normal-level.h)

target_link_libraries(minesweeper PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main)
target_include_directories(minesweeper PRIVATE include)