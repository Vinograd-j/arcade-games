add_executable(arcade-games
        arcade-games.cpp
        src/main-menu.cpp
        src/snake-game-menu.cpp
        src/minesweeper-main-menu.cpp)

target_link_libraries(arcade-games PRIVATE arcade-lib snake-game minesweeper sfml-graphics sfml-window sfml-system sfml-main)
target_include_directories(arcade-games PRIVATE include)