cmake_minimum_required(VERSION 3.15)
project(screen C)

set(SCREEN_SOURCES screen.h screen.c)
add_library(screen ${SCREEN_SOURCES})
target_link_libraries(screen ansi keypress menu)