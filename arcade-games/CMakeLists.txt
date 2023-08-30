add_executable(arcade-games WIN32
        arcade-games.cpp
        src/main-menu.cpp
        src/snake-game-menu.cpp
        src/minesweeper-main-menu.cpp)


target_link_libraries(arcade-games PRIVATE arcade-lib sfml-system snake-game minesweeper sfml-graphics sfml-window sfml-main)

target_include_directories(arcade-games PRIVATE include)

file(COPY ${CMAKE_SOURCE_DIR}/libs/openal32.dll DESTINATION bin)