#include "screen.h"

void resize_screen(int lines, int cols) {
    printf("\x1B[8;%d;%dt", lines, cols);
}