cmake_minimum_required(VERSION 3.14)
project(ImageViewer C)

set(CMAKE_C_STANDARD 11)

# 等价于 -Wall -Wextra -g
add_compile_options(-Wall -Wextra -g)

# 找 SDL2
find_package(SDL2 REQUIRED)

add_executable(iv
    src/main.c
    src/sdl_manager.c
    src/file_manager.c
)

target_include_directories(iv PRIVATE
    ${SDL2_INCLUDE_DIRS}
    src
)
target_compile_definitions(iv PRIVATE _REENTRANT)
target_link_libraries(iv PRIVATE SDL2::SDL2)
