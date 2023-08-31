if(BUILD_SHARED_LIBS)
    set(LIB_TYPE SHARED)
else()
    set(LIB_TYPE STATIC)
endif()

add_library(minesweeper ${LIB_TYPE}
            src/cell.cpp
            src/level.cpp
            src/level-window.cpp
            src/json_config.cpp
           )

target_link_libraries(minesweeper PRIVATE sfml-audio arcade-lib sfml-system sfml-main sfml-graphics sfml-window)

target_include_directories(minesweeper PRIVATE include ${CMAKE_SOURCE_DIR}/json)