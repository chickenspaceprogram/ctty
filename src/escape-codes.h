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

#define RESET_COLORS                    "\x1B[0m" // Resets colors (also resets things like bold text)
#define INVERT_COLORS                   "\x1B[47m\x1B[30m" // Inverts colors. Makes background white and text black.
#define BOLD_TEXT                       "\x1B[1m" // Makes text bold

#define CURSOR_TO_POSITION(row, col)    printf("\x1B[%d;%dH", row, col) // Moves cursor to position (row, col).
#define CURSOR_TO_COL(col)              printf("\x1B[%dG", col) // Moves cursor to column `col`.
#define CURSOR_UP(rows)                 printf("\x1B[%dA", rows) // Moves cursor up by `rows` lines.
#define CURSOR_DOWN(rows)               printf("\x1B[%dB", rows) // Moves cursor down by `rows` lines.

#define DRAW_MODE                       "\x1B(0" // Puts the terminal into draw mode, where line-drawing characters are drawn instead of ASCII characters
#define ASCII_MODE                      "\x1B(B" // Takes the terminal out of line-drawing mode and puts it back in ASCII mode.

#endif