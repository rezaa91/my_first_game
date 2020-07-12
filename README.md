## MY FIRST GAME

Created using SDL2 and C++

To Build:
1. clone the repository
2. update properties > C/C++ > general > additional_include_directories to point to your local SDL2 and SDL2_image includes dir
3. update properties > linker > general > additional_library_directories to point to your local SDL2 and SDL2_image lib dir
4. update properties > linker > input > additional_dependencies - set to include SDL2.lib;SDL2main.lib;SDL2_image.lib;
5. build and run the project in x86
