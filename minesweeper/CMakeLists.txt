add_library(minesweeper STATIC
            src/cell.cpp
            src/level.cpp
            src/level-window.cpp include/easy-level.h include/normal-level.h include/config.h include/json_config.h src/json_config.cpp)

target_link_libraries(minesweeper PRIVATE sfml-audio arcade-lib sfml-system sfml-main sfml-graphics sfml-window
                    ${CMAKE_SOURCE_DIR}/libs/libopenal32.a
                    ${CMAKE_SOURCE_DIR}/libs/libFLAC.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisenc.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisfile.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbis.a
                    ${CMAKE_SOURCE_DIR}/libs/libogg.a)

target_include_directories(minesweeper PRIVATE include ${CMAKE_SOURCE_DIR}/json)