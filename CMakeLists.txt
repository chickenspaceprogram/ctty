cmake_minimum_required(VERSION 3.15)
project(
    ctty
    VERSION 5.0
    DESCRIPTION "A simple C terminal graphics library."
    LANGUAGES C)

add_library(ctty INTERFACE)
add_subdirectory(ansi)
add_subdirectory(keypress)
add_subdirectory(screen)
add_subdirectory(menu)
#add_executable(main "main.c") // for testing purposes
target_link_libraries(ctty INTERFACE ansi keypress screen menu)