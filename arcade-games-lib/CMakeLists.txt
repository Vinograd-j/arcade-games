add_library(arcade-lib STATIC
        src/button.cpp
        src/menu.cpp
        src/random.cpp
        src/sound.cpp
        )

target_include_directories(arcade-lib PUBLIC include)
target_link_libraries(arcade-lib PRIVATE sfml-audio sfml-system  sfml-window sfml-graphics
                    ${CMAKE_SOURCE_DIR}/libs/libopenal32.a
                    ${CMAKE_SOURCE_DIR}/libs/libFLAC.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisenc.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbisfile.a
                    ${CMAKE_SOURCE_DIR}/libs/libvorbis.a
                    ${CMAKE_SOURCE_DIR}/libs/libogg.a)