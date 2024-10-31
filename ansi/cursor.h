#ifndef ANSI_CURSOR_H
#define ANSI_CURSOR_H

#include "keypress.h"

typedef struct position {
    int row;
    int col;
} Position;

#define CURSOR_HOME
#define CURSOR_TO_POSITION(row, col)    printf("\x1B[%d;%dH", row, col) // Moves cursor to position (row, col).
#define CURSOR_UP(rows)                 printf("\x1B[%dA", rows) // Moves cursor up by `rows` lines.
#define CURSOR_DOWN(rows)               printf("\x1B[%dB", rows) // Moves cursor down by `rows` lines.
#define CURSOR_LEFT
#define CURSOR_RIGHT


/**
 * Function name: get_cursor_position
 * Date created: 31 Oct 2024
 * Date last modified: 31 Oct 2024
 * Description: Returns a struct containing the current position of the cursor
 * Inputs: none
 * Outputs: A struct containing the current position of the cursor.
 */
Position get_cursor_position(void);

#endif