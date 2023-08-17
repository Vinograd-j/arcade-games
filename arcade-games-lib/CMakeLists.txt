set(HEADERS include)

add_library(arcade-lib STATIC
        src/button.cpp
        src/menu.cpp
        src/random.cpp)

target_include_directories(arcade-lib PUBLIC ${HEADERS})
target_link_libraries(arcade-lib PRIVATE sfml-window sfml-graphics)
