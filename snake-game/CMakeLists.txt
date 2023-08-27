add_library(snake-game STATIC
        src/field.cpp
        src/food.cpp
        src/level.cpp
        src/snake.cpp
        src/witch_level.cpp
        src/level-window.cpp)

target_link_libraries(snake-game PRIVATE arcade-lib sfml-audio sfml-graphics sfml-window sfml-system sfml-main
                    ${CMAKE_SOURCE_DIR}/libs/libopenal32.a
                    ${CMAKE_SOURCE_DIR}/libs/libFLAC.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisenc.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisfile.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbis.a
                    ${CMAKE_SOURCE_DIR}/libs/libogg.a)

target_include_directories(snake-game PRIVATE include)