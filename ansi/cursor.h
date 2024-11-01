#ifndef ANSI_CURSOR_H
#define ANSI_CURSOR_H

#include "../keypress.h"

typedef struct position {
    int row;
    int col;
} Position;

#define CURSOR_HOME                     "\x1B[H" // moves the cursor to position (0, 0)

#define CURSOR_UP(rows)                 printf("\x1B[%dA", rows) // Moves cursor up by `rows` lines.
#define CURSOR_DOWN(rows)               printf("\x1B[%dB", rows) // Moves cursor down by `rows` lines.
#define CURSOR_RIGHT(cols)              printf("\x1B[%dC", cols) // Moves cursor right by `cols` lines.
#define CURSOR_LEFT(cols)               printf("\x1B[%dD", cols) // Moves cursor left by `cols` lines.

#define CURSOR_DOWN_LINE_START(rows)    printf("\x1B[%dE", rows) // moves the cursor down by `rows` lines and to the start of the line it lands on
#define CURSOR_UP_LINE_START(rows)      printf("\x1B[%dF", rows) // moves the cursor up by `rows` lines and to the start of the line it lands on
#define CURSOR_UP_SCROLL                "\x1B M" // Moves cursor up one line, scrolling if needed

#define CURSOR_TO_COL(col)              printf("\x1B[%dG", col) // Moves cursor to column `col`.
#define CURSOR_TO_POSITION(row, col)    printf("\x1B[%d;%dH", row, col) // Moves cursor to position (row, col).

#define SAVE_CURSOR                     "\x1B 7" // Saves the cursor's position
#define LOAD_CURSOR                     "\x1B 8" // Loads the cursor from the saved position in memory



/**
 * Function name: cursor_get_position
 * Date created: 31 Oct 2024
 * Date last modified: 31 Oct 2024
 * Description: Returns a struct containing the current position of the cursor
 * Inputs: none
 * Outputs: A struct containing the current position of the cursor.
 */
Position cursor_get_position(void);

#endif