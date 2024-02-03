# ARCADE-GAMES

**How to build this project with CMake:**

1.  Download this repository.

2. Open CMD in root folder.

3. Use `mkdir build` to create a folder where the project will be built

4. Use `cd build` to go into the created folder. 

5. Write: `cmake -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=ON ..`. You can write OFF in the `BUILD_SHARED_LIBS` option, then the SFML library will be built as static. ( SFML library will be downloaded automatically ).
    ##### You can use flag `MOVE_SYSTEM_LIBS=ON/OFF`. in order to move the necessary system dll files to the bin folder. This is necessary in cases where you want to give a build to another person who does not have MinGW and, accordingly, does not have these system libraries installed. 

7. Now you can compile the project using `mingw32-make`. The executable file will be in arcade-games/bin

You have to download the MinGW compiler, which recomended by SFML. [MinGW x64](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z "MinGW x64 link") and [MinGW x32](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z "MinGW x32 link")

# Main Menu

![image](https://github.com/Vinograd-j/arcade-games/assets/84085491/78c55a7d-5a8c-4576-8490-f8edc808ee31)

------------

# SnakeGame main menu

![image](https://github.com/Vinograd-j/arcade-games/assets/84085491/4595f478-cfe5-454c-8c42-e9b149d9e33d)

# Minesweeper main menu

![image](https://github.com/Vinograd-j/arcade-games/assets/84085491/2ac2bbc0-0e62-44c6-80b1-6eefc54b7f19)

# SnakeGame level (each level has unique colors)

![image](https://github.com/Vinograd-j/arcade-games/assets/84085491/f9f37240-fdff-40ce-ac0c-4d5c02842768)

# Minesweeper level 

![image](https://github.com/Vinograd-j/arcade-games/assets/84085491/944de585-6ff1-4aa3-84de-ee6e3433bc7e)

