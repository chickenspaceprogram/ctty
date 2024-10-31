#ifndef ANSI_ERASE_H
#define ANSI_ERASE_H

#define ERASE_CURSOR_TO_END         "\x1B[0J"
#define ERASE_TO_CURSOR             "\x1B[1J"
#define ERASE_SCREEN                "\x1B[2J"
#define ERASE_SAVED_LINES           "\x1B[3J"

#define ERASE_CURSOR_TO_LINE_END    "\x1B[0K"
#define ERASE_START_LINE_TO_CURSOR  "\x1B[1K"
#define ERASE_LINE                  "\x1B[2K"

#endif