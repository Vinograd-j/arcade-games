add_library(minesweeper SHARED
            src/cell.cpp
            src/level.cpp
            src/level-window.cpp include/easy-level.h include/normal-level.h include/config.h include/json_config.h src/json_config.cpp)

target_link_libraries(minesweeper PRIVATE sfml-audio arcade-lib sfml-system sfml-main sfml-graphics sfml-window)

target_include_directories(minesweeper PRIVATE include ${CMAKE_SOURCE_DIR}/json)