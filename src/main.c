#include <stdio.h>
#include "keyselect.h"
#include "keycodes.h"

int main(void) {
    sequence seqs[] = {
        CTTY_UP,
        CTTY_DOWN,
        CTTY_LEFT,
        CTTY_RIGHT,
        CTTY_ESC,
        CTTY_DEL,
    };
    printf("%d\n", select_char(seqs, 6));
}