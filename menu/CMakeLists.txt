cmake_minimum_required(VERSION 3.15)
project(menu C)

set(MENU_SOURCES menu.c menu.h)
add_library(menu ${MENU_SOURCES})
target_link_libraries(menu ansi keypress screen)