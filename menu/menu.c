#include "menu.h"

/**
 * Function name: up_row
 * Date created: 10/22/2024
 * Date last modified: 3 Nov 2024
 * Description: Returns the index of the option that is one row up from the current option.
 * Inputs: 
 * `options` : An array of `option` structs containing the various menu options.
 * `current_selection` : The index of the user's current selection.
 * Outputs: The index of the option that is one row up from the current option.
 */
static int up_row(Option *options, size_t num_options, size_t current_selection);

/**
 * Function name: down_row
 * Date created: 10/22/2024
 * Date last modified: 3 Nov 2024
 * Description: Returns the index of the option that is one row down from the current option.
 * Inputs: 
 * `options` : An array of `option` structs containing the various menu options.
 * `current_selection` : The index of the user's current selection.
 * Outputs: The index of the option that is one row down from the current option.
 */
static int down_row(Option *options, size_t num_options, size_t current_selection);

static void fill_sequence_array(sequence *seqs, Option *options, size_t num_rows);

static void print_row(Option *options, size_t *row_nums, size_t row_to_print, size_t row_len);

static void invert_row(Option *options, size_t *row_nums, size_t row_to_print, size_t row_len);

static size_t find_row(Option *options, size_t num_options, char *select_sequence);

size_t select_menu_option(Menu menu, size_t num_options) {
    size_t *row_offsets = malloc(sizeof(size_t) * num_options);
    size_t current_row = -1;
    size_t menu_len = find_menu_len(menu);
    sequence *sequences = malloc(sizeof(sequence) * (num_options + 5));
    size_t selection = -1;

    if (sequences == NULL || row_offsets == NULL) {
        return -2;
    }

    current_row = down_row(menu.options, num_options, current_row);
    fill_sequence_array(sequences, menu.options, num_options);

    if (current_row == -1) {
        return -1;
    }

    // printing menu
    print_menu(menu, row_offsets, num_options, menu_len);

    // inverting first row
    invert_row(menu.options, row_offsets, current_row, menu_len);


    do {
        selection = select_char(sequences, num_options + 5);
        switch (selection) {

        }

    } while ();

    free(sequences);
    free(row_offsets);
}

 print_menu(Menu menu, size_t *row_offsets, size_t num_options, size_t menu_len) {

    find_row_nums(menu, row_offsets);

    print_title(menu.title, menu_len);

    for (int i = 0; i < num_options; ++i) {
        if (menu.options[i].is_valid) {
            print_row(menu.options, row_offsets, i, menu_len - 2);
        }
    }
}

size_t find_menu_len(Menu menu) {
    size_t longest_len = strlen(menu.title);
    size_t current_len;
    for (int i = 0; i < menu.num_options; ++i) {
        if ((current_len = strlen(menu.options[i].msg)) > longest_len) {
            longest_len = current_len;
        }
    }
    return longest_len + 2;
}

size_t find_row_nums(Menu menu, size_t *row_nums) {
    size_t current_row = 0;
    for (size_t i = 0; i < menu.num_options; ++i) {
        if (menu.options[i].is_valid) {
            row_nums[i] = current_row++;
        }
    }
    return current_row;
}

void fill_with_value(size_t *arr, size_t value, size_t len) {
    for (int i = 0; i < len; ++i) {
        arr[i] = value;
    }
}

void print_title(char *title, size_t table_size) {
    size_t title_len = strlen(title);
    size_t spaces_to_print = (title_len - table_size) / 2;

    fputs("  "MODE_DRAW"l", stdout);
    for (int i = 0; i < table_size; ++i) {
        putchar('q');
    }
    fputs("k\nx"MODE_DRAW_RESET, stdout);

    for (int i = 0; i < spaces_to_print; ++i) {
        putchar(' ');
    }
    fputs(title, stdout);
    for (int i = title_len + spaces_to_print; i < table_size) {
        putchar(' ');
    }


    fputs(MODE_DRAW"x\n  t", stdout);

    for (int i = 0; i < table_size; ++i) {
        putchar('q');
    }
    fputs("u\n"MODE_DRAW_RESET, stdout);
}



/* Private Functions */

int up_row(Option *options, size_t num_options, size_t current_selection) {
    if (current_selection == 0) {
        return current_selection; // already at the beginning!
    }
    for (size_t i = current_selection - 1; i >= 0; --i) {
        if (options[i].is_valid) {
            return i; // if we find a valid option, stop and return it!
        }
    }
    return current_selection; // couldn't find an earlier valid selection
}

int down_row(Option *options, size_t num_options, size_t current_selection) {
    if (current_selection == num_options - 1) {
        return current_selection; // already at the end!
    }
    for (size_t i = current_selection + 1; i < num_options; ++i) {
        if (options[i].is_valid) {
            return i; // if we find a valid option, stop and return it!
        }
    }

    return current_selection; // couldn't find an earlier valid selection
}

void fill_sequence_array(sequence *seqs, Option *options, size_t num_rows) {
    size_t current_row = 0;
    sequence up = CTTY_UP;
    sequence down = CTTY_DOWN;
    sequence letter_j = CTTY_j;
    sequence letter_k = CTTY_k;
    sequence enter = CTTY_ENTER;

    seqs[current_row++] = up;
    seqs[current_row++] = down;
    seqs[current_row++] = letter_k;
    seqs[current_row++] = letter_j;
    seqs[current_row++] = enter;

    for (size_t i = 0; i < num_rows; ++i) {
        if (options[i].is_valid) {
            seqs[current_row].chars = options->selection_seq;
            seqs[current_row].len = strlen(options->selection_seq);
            ++current_row;
        }
    }
}

void print_row(Option *options, size_t *row_nums, size_t row_to_print, size_t row_len) {
    size_t msg_len = 0;
    if (row_nums[row_to_print] != 0) {
        CURSOR_DOWN_LINE_START(row_nums[row_to_print]);
    }

    fputs("> "MODE_DRAW"x "MODE_DRAW_RESET, stdout);
    while (options[row_to_print].msg[msg_len] != '\0') {
        putchar(options[row_to_print].msg[msg_len++]);
    }

    while (msg_len < row_len) {
        putchar(' ');
    }

    fputs("x"MODE_DRAW_RESET" <", stdout);

    if (row_nums[row_to_print] != 0) {
        CURSOR_UP_LINE_START(row_nums[row_to_print]);
    }
}

void invert_row(Option *options, size_t *row_nums, size_t row_to_print, size_t row_len) {
    size_t msg_len = 0;
    if (row_nums[row_to_print] != 0) {
        CURSOR_DOWN_LINE_START(row_nums[row_to_print]);
    }

    fputs("> "MODE_DRAW"x "MODE_DRAW_RESET MODE_INVERSE, stdout);
    while (options[row_to_print].msg[msg_len] != '\0') {
        putchar(options[row_to_print].msg[msg_len++]);
    }

    while (msg_len < row_len) {
        putchar(' ');
    }

    fputs(MODE_INVERSE "x"MODE_DRAW_RESET" <", stdout);

    if (row_nums[row_to_print] != 0) {
        CURSOR_UP_LINE_START(row_nums[row_to_print]);
    }
}

static size_t find_row(Option *options, size_t num_options, char *select_sequence) {
    
}