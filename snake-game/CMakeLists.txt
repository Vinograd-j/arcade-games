add_library(snake-game STATIC
        src/field.cpp
        src/food.cpp
        src/level.cpp
        src/snake.cpp
        src/witch_level.cpp
        src/level-window.cpp)

target_link_libraries(snake-game PRIVATE arcade-lib sfml-graphics sfml-window sfml-system sfml-main sfml-audio)
target_include_directories(snake-game PRIVATE include)