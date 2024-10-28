cmake_minimum_required(VERSION 3.30)

project(ctty VERSION 0.1 LANGUAGES C)

add_executable(ctty ../src/main.c)

target_include_directories(ctty PUBLIC $(CMAKE_CURRENT_SOURCE_DIR)/src)