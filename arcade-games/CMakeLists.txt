add_executable(arcade-games WIN32
        arcade-games.cpp include/main-menu.h src/main-menu.cpp)

target_link_libraries(arcade-games PRIVATE arcade-lib snake-game minesweeper sfml-graphics sfml-window sfml-system sfml-main)
target_include_directories(arcade-games PRIVATE include)