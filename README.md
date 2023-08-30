# ARCADE-GAMES

**How to build this project with CMake:**

1.  Download this repository.

2. Open CMD in root folder.

3. Use `mkdir build` to create a folder where the project will be built

4. Use `cd build` to go into the created folder. 

5. Write: `cmake -G "MinGW Makefiles" -DBUILD_SHARED_LIBS=ON ..`. You can write OFF in the `BUILD_SHARED_LIBS` option, then the SFML library will be built as static. ( SFML library will be downloaded automatically ).

6. Now you can compile the project using `mingw32-make`. The executable file will be in arcade-games/bin

You have to download the MinGW compiler, which recomended by SFML. [MinGW x64](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-x86_64-posix-seh-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z "MinGW x64 link") and [MinGW x32](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z "MinGW x32 link")

