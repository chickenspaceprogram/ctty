cmake_minimum_required(VERSION 3.15)
project(ansi)

set(ANSI_SOURCES colors.c colors.h cursor.c cursor.h erase.h text-modes.h)
add_library(ansi ${ANSI_SOURCES})
target_link_libraries(ansi menu keypress screen)