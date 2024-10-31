#include "keyselect.h"

int select_char(sequence *sequences, int num_sequences) {
    int ch = check_char(sequences, num_sequences);
    while (ch == -1) {
        ch = check_char(sequences, num_sequences);
    }
    return ch;
}

int check_char(sequence *sequences, int num_sequences) {
    int valid_matches[num_sequences];
    int longest_match = -1;
    int j = 0;
    int current_char = 0;
    int num_chars_left = num_sequences;


    for (int i = 0; i < num_sequences; ++i) {
        valid_matches[i] = 1;
    }


    while (num_chars_left > 0) {
        current_char = GETCH();
        for (int i = 0; i < num_sequences; ++i) {
            if (valid_matches[i]) {
                if (current_char != sequences[i].chars[j]) {
                    valid_matches[i] = 0;
                    --num_chars_left;
                }
                else if (j == sequences[i].len - 1) {
                    valid_matches[i] = 0;
                    longest_match = i;
                    --num_chars_left;
                }
            }
        }
        ++j;
    }

    return longest_match;
}