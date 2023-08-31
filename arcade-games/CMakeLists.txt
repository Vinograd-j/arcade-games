add_executable(arcade-games WIN32
        arcade-games.cpp
        src/main-menu.cpp
        src/snake-game-menu.cpp
        src/minesweeper-main-menu.cpp)


target_link_libraries(arcade-games PRIVATE sfml-audio arcade-lib sfml-system snake-game minesweeper sfml-graphics sfml-window sfml-main)

target_include_directories(arcade-games PRIVATE include)


if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET arcade-games POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:arcade-games> $<TARGET_FILE_DIR:arcade-games> COMMAND_EXPAND_LISTS)

    file(GLOB DLLS ${CMAKE_SOURCE_DIR}/dlls/system/*.dll)

    file(COPY ${DLLS} DESTINATION ${CMAKE_BINARY_DIR}/arcade-games/bin)

else ()
    set(CMAKE_EXE_LINKER_FLAGS "-static -static-libgcc -static-libstdc++")
endif()

file(COPY ${CMAKE_SOURCE_DIR}/dlls/openal32.dll DESTINATION "${CMAKE_BINARY_DIR}/arcade-games/bin")

file(COPY ${CMAKE_SOURCE_DIR}/resources DESTINATION "${CMAKE_BINARY_DIR}/arcade-games/bin")
file(COPY ${CMAKE_SOURCE_DIR}/configs DESTINATION "${CMAKE_BINARY_DIR}/arcade-games/bin")