add_library(snake-game SHARED
        src/field.cpp
        src/food.cpp
        src/level.cpp
        src/snake.cpp
        src/witch_level.cpp
        src/level-window.cpp include/json_config.h src/json_config.cpp)

target_link_libraries(snake-game PRIVATE arcade-lib sfml-audio sfml-system sfml-main sfml-graphics sfml-window)

target_include_directories(snake-game PRIVATE include ${CMAKE_SOURCE_DIR}/json)