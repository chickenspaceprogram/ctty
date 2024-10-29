#include <stdio.h>
#include "keyselect.h"
#include "keypress-codes.h"

int main(void) {
    sequence seqs[] = {
        CTTY_UP,
        CTTY_DOWN,
        CTTY_LEFT,
        CTTY_RIGHT,
        {"a", 1},
        {"s", 1},
        {"d", 1},
        {"f", 1},
    };
    printf("%d\n", select_char(seqs, 8));
}