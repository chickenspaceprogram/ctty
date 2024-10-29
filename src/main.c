#include <stdio.h>
#include "keypress.h"

int main(void) {
    while (1) {
        printf("%x\n", GETCH());
    }
}