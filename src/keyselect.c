#include "keyselect.h"

int select_char(const char **char_sequences, int *sequence_lengths, int num_sequences) {
    int ch = check_char(char_sequences, sequence_lengths, num_sequences);
    while (ch == -1) {
        ch = check_char(char_sequences, sequence_lengths, num_sequences);
    }
    return ch;
}

int check_char(const char **char_sequences, int *sequence_lengths, int num_sequences) {
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
                if (current_char != char_sequences[i][j]) {
                    valid_matches[i] = 0;
                    --num_chars_left;
                }
                else if (j == sequence_lengths[i] - 1) {
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