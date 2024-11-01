#include "cursor.h"

/**
 * Function name: read_number
 * Date created: 31 Oct 2024
 * Date last modified: 31 Oct 2024
 * Description: Reads a number from stdin, stopping when a ';' or an 'R' is detected.
 * Inputs: none
 * Outputs: The number that was read.
 */
static int read_number(void);


int read_number(void) {
    int ch = 0, num = 0;
    while ((ch = GETCH()) != ';' && ch != 'R') {
        if (ch < '0' || ch > '9') {
            return -1;
        }
        num *= 10;
        num += ch - '0';
    }
    return num;
}

Position cursor_get_position(void) {
    Position pos;
    printf("\x1B[6n");
    GETCH(); GETCH(); // getting rid of escape and `[` chars
    pos.row = read_number();
    pos.col = read_number();
    return pos;
}