cmake_minimum_required(VERSION 3.25)
project(arcade_games)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc")
set(SFML_STATIC_LIBRARIES TRUE)


find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_subdirectory(arcade-games-lib)

add_subdirectory(snake-game)

add_subdirectory(minesweeper)

add_subdirectory(arcade-games)
set_target_properties(arcade-games PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/arcade-games/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/arcade-games/bin"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/arcade-games/bin"
)

file(COPY resources DESTINATION "${CMAKE_BINARY_DIR}/arcade-games/bin")