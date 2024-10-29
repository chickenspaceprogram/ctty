#include <stdio.h>
#include "keyselect.h"

int main(void) {
    char *seqs[] = {
        "\x1b[A",
        "\x1b[B",
        "\x1b[D",
        "\x1b[C",
    };
    int seq_lens[] = {3, 3, 3, 3};
    int num_seqs = 4;
    printf("%d\n", select_char(seqs, seq_lens, num_seqs));
}