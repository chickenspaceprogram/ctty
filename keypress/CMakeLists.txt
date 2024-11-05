cmake_minimum_required(VERSION 3.15)
project(keypress)

set(KEYPRESS_SOURCES keypress-codes.h keypress.c keypress.h keyselect.c keyselect.h)
add_library(keypress ${KEYPRESS_SOURCES})
target_link_libraries(keypress ansi menu screen)