cmake_minimum_required(VERSION 3.15)
project(keypress)

set(KEYPRESS_SOURCES colors.c colors.h cursor.c cursor.h erase.h text-modes.h)
add_library(keypress ${ANSI_SOURCES})
target_link_libraries(ansi keypress screen)