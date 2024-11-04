target_include_directories()
add_subdirectory(ansi)
ADD_LIBRARY(ctty keypress-codes.h keypress.c keypress.h keyselect.c keyselect.h screen.h ansi)