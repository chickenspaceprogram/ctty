// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

// apologies for the poor internal design of this.
// a lot of functions get repeated and it's in dire need of a refactor tbh

#include "menu.h"

typedef enum {
    Up,
    Down,
    K,
    J,
    Enter,
} Keys;

/**
 * Function name: find_max_msg_len
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Finds the length of the longest message or title in the menu.
 * Inputs: 
 * `options` : An array containing all the options in the menu
 * `title` : The title of the menu
 * `num_msgs` : The number of options in the menu.
 * Outputs: The length of the longest message or title in the menu. 
 */
static size_t find_max_msg_len(Option *options, unsigned char *title, size_t num_msgs);

/**
 * Function name: print_title
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Prints the title of the menu, including the borders around it.
 * Inputs: 
 * `title` : A string containing the title of the menu.
 * `table_size` : The width of the table.
 * Outputs: none
 */
static void print_title(char *title, size_t table_size);

/**
 * Function name: print_row
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Prints a single row of the table in the correct place, with normal colors.
 * Inputs: 
 * `row` : The text of the row
 * `position` : The position in which to print the row
 * `len` : The length of the longest message in the menu.
 * Outputs: none
 */
static void print_row(char *row, size_t position, size_t len);

/**
 * Function name: inverse_row
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Prints a single row of the table in the correct place, with inverted colors.
 * Inputs: 
 * `row` : The text of the row
 * `position` : The position in which to print the row
 * `len` : The length of the longest message in the menu.
 * Outputs: none
 */
void inverse_row(char *row, size_t position, size_t len);

/**
 * Function name: print_bottom
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Prints the bottom of the menu.
 * Inputs: 
 * `num_rows` : The number of rows in the menu
 * `row_len` : The length of each row in the menu
 * Outputs: none
 */
static void print_bottom(size_t num_rows, size_t row_len);

/**
 * Function name: fill_sequence_array
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Allocates an array of `sequence` structs on the heap, and initializes them with the correct values.
 * Inputs: 
 * `options` : An array of structs containing both the message and the sequence of characters that go along with each option.
 * 
 * 
 * 
 * `num_options` : The number of options.
 * Outputs: A pointer to the array of `sequence` structs.
 */
sequence *fill_sequence_array(Option *options, sequence *extra_seqs, size_t num_options, size_t num_extra_seqs);

void print_row_txt(char *row, size_t len);


size_t menu(Option *options, char *title, size_t num_options) {
    sequence extra_seqs[5] = {
        CTTY_UP,
        CTTY_DOWN,
        CTTY_k,
        CTTY_j,
        CTTY_ENTER,
    };
    fputs(CURSOR_OFF, stdout);
    sequence *seqs = fill_sequence_array(options, extra_seqs, num_options, 5);
    if (seqs == NULL) {
        return -1;
    }

    size_t len = find_max_msg_len(options, title, num_options);
    size_t current_row = 0, prev_row = 0;
    Keys user_selection = Enter;
    print_title(title, len);
    for (int i = 0; i < num_options; ++i) {
        print_row(options[i].msg, i, len);
    }
    print_bottom(num_options, len);
    while (1) {
        user_selection = select_char(seqs, num_options + 5);
        if (user_selection < num_options) {
            if (user_selection != current_row) {
                print_row(options[current_row].msg, current_row, len);
                current_row = user_selection;
            }
        }
        else if (user_selection == (num_options) || user_selection == (num_options + 2)) {
            if (current_row > 0) {
                print_row(options[current_row].msg, current_row, len);
                --current_row;
            }
        }
        else if (user_selection == (num_options + 1) || user_selection == (num_options + 3)) {
            if (current_row < (num_options - 1)) {
                print_row(options[current_row].msg, current_row, len);
                ++current_row;
            }
        }
        else {
            free(seqs);
            fputs(CURSOR_ON, stdout);
            return current_row;
        }
        inverse_row(options[current_row].msg, current_row, len);
    }
}

void multimenu(Option *options, char *title, size_t num_options, bool *selections, size_t max_num_selections) {
    for (size_t i = 0; i < num_options; ++i) {
        selections[i] = false;
    }
    sequence extra_seqs[6] = {
        CTTY_UP,
        CTTY_DOWN,
        CTTY_k,
        CTTY_j,
        CTTY_ENTER,
        CTTY_SPACE,
    };
    fputs(CURSOR_OFF, stdout);
    sequence *seqs = fill_sequence_array(options, extra_seqs, num_options, 6);
    if (seqs == NULL) {
        return -1;
    }

    size_t len = find_max_msg_len(options, title, num_options);
    size_t current_row = 0, prev_row = 0;
    Keys user_selection = Enter;
    print_title(title, len);
    for (int i = 0; i < num_options; ++i) {
        print_row(options[i].msg, i, len);
    }
    print_bottom(num_options, len);
    while (1) {
        user_selection = select_char(seqs, num_options + 5);
        if (user_selection < num_options) {
            if (user_selection != current_row) {
                print_row(options[current_row].msg, current_row, len);
                current_row = user_selection;
            }
        }
        else if (user_selection == (num_options) || user_selection == (num_options + 2)) {
            if (current_row > 0) {
                print_row(options[current_row].msg, current_row, len);
                --current_row;
            }
        }
        else if (user_selection == (num_options + 1) || user_selection == (num_options + 3)) {
            if (current_row < (num_options - 1)) {
                print_row(options[current_row].msg, current_row, len);
                ++current_row;
            }
        }
        else if (user_selection == (num_options + 6)) {
            selections[current_row] = !(selections[current_row]);
            if (selections[current_row]) {
                inverse_row(options[current_row].msg, current_row, len);
            }
            else {
                print_row(options[current_row].msg, current_row, len);
            }
            continue;
        }
        else {
            free(seqs);
            fputs(CURSOR_ON, stdout);
            return current_row;
        }
        if (current_row != 0) {
            CURSOR_DOWN_LINE_START(current_row);
        }
        fputs("> ", stdout);
        print_row_txt(options[current_row].msg, len);
        fputs(" <", stdout);
        if (current_row != 0) {
            CURSOR_UP_LINE_START(current_row);
        }
        else {
            putchar('\r');
        }
    }
}


size_t find_max_msg_len(Option *options, unsigned char *title, size_t num_msgs) {
    size_t longest_len = strlen((char *)title);
    size_t current_len;
    for (int i = 0; i < num_msgs; ++i) {
        if ((current_len = strlen((char *)options[i].msg)) > longest_len) {
            longest_len = current_len;
        }
    }
    return longest_len;
}

void print_title(char *title, size_t table_size) {
    size_t title_len = strlen((char *)title);

    fputs("  "MODE_DRAW"l", stdout);
    for (int i = 0; i < (table_size + 2); ++i) {
        putchar('q');
    }
    fputs("k\n  x "MODE_DRAW_RESET, stdout);

    fputs((char *)title, stdout);
    for (int i = strlen((char *)title); i < (table_size + 1); ++i) {
        putchar(' ');
    }

    fputs(MODE_DRAW"x\n  t", stdout);

    for (int i = 0; i < (table_size + 2); ++i) {
        putchar('q');
    }
    fputs("u\n"MODE_DRAW_RESET, stdout);
}

void print_row(char *row, size_t position, size_t len) {
    size_t msg_len = 0;
    if (position != 0) {
        CURSOR_DOWN_LINE_START((int)position);
    }

    fputs("  "MODE_DRAW"x "MODE_DRAW_RESET, stdout);
    fputs((char *)row, stdout);

    for (int i = strlen((char *)row); i < (len + 1); ++i) {
        putchar(' ');
    }

    fputs(MODE_DRAW"x"MODE_DRAW_RESET"  ", stdout);

    if (position != 0) {
        CURSOR_UP_LINE_START((int)position);
    }
    else {
        putchar('\r');
    }
}

void inverse_row(char *row, size_t position, size_t len) {
    size_t msg_len = 0;
    if (position != 0) {
        CURSOR_DOWN_LINE_START((int)position);
    }

    fputs("> "MODE_DRAW"x "MODE_DRAW_RESET MODE_INVERSE, stdout);
    fputs(row, stdout);
    fputs(MODE_INVERSE_RESET, stdout);

    for (int i = strlen(row); i < (len + 1); ++i) {
        putchar(' ');
    }

    fputs(MODE_DRAW"x"MODE_DRAW_RESET" <", stdout);

    if (position != 0) {
        CURSOR_UP_LINE_START((int)position);
    }
    else {
        putchar('\r');
    }
}

static void print_bottom(size_t num_rows, size_t row_len) {
    CURSOR_DOWN_LINE_START((int)num_rows);
    fputs("  "MODE_DRAW"m", stdout);
    for (int i = 0; i < (row_len + 2); ++i) {
        putchar('q');
    }
    fputs("j"MODE_DRAW_RESET, stdout);
    CURSOR_UP_LINE_START((int)num_rows);
}

sequence *fill_sequence_array(Option *options, sequence *extra_seqs, size_t num_options, size_t num_extra_seqs) {
    sequence *seqs = malloc(sizeof(sequence) * (num_options + num_extra_seqs));
    if (seqs == NULL) {
        return NULL;
    }

    for (int i = 0; i < num_options; ++i) {
        seqs[i].chars = options[i].sequence;
        seqs[i].len = strlen((char *)options[i].sequence);
    }
    for (int i = num_options; i < (num_options + num_extra_seqs); ++i) {
        seqs[i] = extra_seqs[i - num_options];
    }
    return seqs;
}

void print_row_txt(char *row, size_t len) {
    size_t msg_len = 0;

    fputs(MODE_DRAW"x "MODE_DRAW_RESET, stdout);
    fputs(row, stdout);

    for (int i = strlen(row); i < (len + 1); ++i) {
        putchar(' ');
    }

    fputs(MODE_DRAW"x"MODE_DRAW_RESET, stdout);
}