add_library(arcade-lib STATIC
        src/button.cpp
        src/menu.cpp
        src/random.cpp
        src/sound.cpp
        )

target_include_directories(arcade-lib PUBLIC include)
target_link_libraries(arcade-lib PRIVATE sfml-audio sfml-system  sfml-window sfml-graphics)