#include "cursor.h"

Position get_cursor_position(void) {
    printf("\x1B[6n");
}