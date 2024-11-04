cmake_minimum_required(VERSION 3.15)
project(
    ctty
    VERSION 5.0
    DESCRIPTION "A simple C terminal graphics library."
    LANGUAGES C)
add_subdirectory(ansi)
add_subdirectory(keypress)
add_library(screen screen.h)
target_link_libraries(ansi keypress screen)