set(INCLUDE include)

set(ARCADE_GAMES_LIB_INCLUDE ../arcade-games-lib/include)

add_executable(snake-game WIN32 snake-game.cpp
        src/field.cpp
        src/food.cpp
        src/level.cpp
        src/menu.cpp
        src/snake.cpp
        src/witch_level.cpp)

target_link_libraries(snake-game PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main )
target_include_directories(snake-game PRIVATE ${INCLUDE} ${ARCADE_GAMES_LIB_INCLUDE})