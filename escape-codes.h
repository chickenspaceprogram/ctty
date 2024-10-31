/**
 * This file contains handy macros for some common ANSI escape codes.
 * To use most of these, just printf() them or use the fact that C concatenates string literals that are next to each other.
 * To use the ones that take arguments, just call them like you would any normal function.
 */

#ifndef ESCAPE_CODES_H
#define ESCAPE_CODES_H

#define HIDE_CURSOR                     "\x1B[?25l" // Hides the cursor
#define SHOW_CURSOR                     "\x1B[?25h" // Shows the cursor
#define SAVE_CURSOR                     "\x1B 7" // Saves the cursor's position
#define LOAD_CURSOR                     "\x1B 8" // Loads the cursor from the saved position in memory

// macros for foreground and background colors



#define CURSOR_TO_POSITION(row, col)    printf("\x1B[%d;%dH", row, col) // Moves cursor to position (row, col).
#define CURSOR_TO_COL(col)              printf("\x1B[%dG", col) // Moves cursor to column `col`.

#endif