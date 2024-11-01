#include "keyselect.h"

int select_char(sequence *sequences, int num_sequences) {
    int ch = check_char(sequences, num_sequences);
    while (ch == -1) {
        ch = check_char(sequences, num_sequences);
    }
    return ch;
}

int check_char(sequence *sequences, int num_sequences) {
    ArrayList *valid_matches = newArrayList(sizeof(int));
    int longest_match = -1, j = 0, current_char = 0, num_chars_left = num_sequences, one = 1, zero = 0;
    void *is_valid_ptr;

    for (int i = 0; i < num_sequences; ++i) {
        valid_matches->push(valid_matches, &one); // setting valid_matches[i] = 1
    }


    while (num_chars_left > 0) {
        current_char = GETCH();
        for (int i = 0; i < num_sequences; ++i) {

            is_valid_ptr = valid_matches->get(valid_matches, i); // not checking for null since we're always inside the bounds of the arraylist

            if (*(int *)is_valid_ptr) {
                if (current_char != sequences[i].chars[j]) {
                    valid_matches->set(valid_matches, i, &zero); // setting valid_matches[i] = 0
                    --num_chars_left;
                }
                else if (j == sequences[i].len - 1) {
                    valid_matches->set(valid_matches, i, &zero); // setting valid_matches[i] = 0
                    longest_match = i;
                    --num_chars_left;
                }
            }
        }
        ++j;
    }

    return longest_match;
}