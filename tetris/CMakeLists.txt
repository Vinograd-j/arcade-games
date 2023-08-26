add_library(tetris STATIC
        src/Game.cpp
)

target_include_directories(tetris include)
target_link_libraries(tetris PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main)