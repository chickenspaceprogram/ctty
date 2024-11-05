#include "menu.h"

typedef enum {
    Up,
    Down,
    K,
    J,
    Enter,
} Keys;

static size_t find_max_msg_len(char **msgs, char *title, size_t num_msgs);

static void print_title(char *title, size_t table_size);

static void print_row(char *row, size_t position, size_t len);

static void inverse_row(char *row, size_t position, size_t len);

static void print_bottom(size_t num_rows, size_t row_len);


size_t menu(char **options, char *title, size_t num_options) {
    sequence seqs[5] = {
        CTTY_UP,
        CTTY_DOWN,
        CTTY_k,
        CTTY_j,
        CTTY_ENTER,
    };


    size_t len = find_max_msg_len(options, title, num_options);
    size_t current_row = 0, prev_row = 0;
    Keys user_selection = Enter;
    print_title(title, len);
    inverse_row(options[0], 0, len);
    for (int i = 1; i < num_options; ++i) {
        print_row(options[i], i, len);
    }
    print_bottom(num_options, len);
    while (1) {
        user_selection = (Keys) select_char(seqs, 5);
        switch (user_selection) {
            case Up: case K:
                if (current_row > 0) {
                    print_row(options[current_row], current_row, len);
                    --current_row;
                    inverse_row(options[current_row], current_row, len);
                }
                break;
            case Down: case J:
                if (current_row < (num_options - 1)) {
                    print_row(options[current_row], current_row, len);
                    ++current_row;
                    inverse_row(options[current_row], current_row, len);
                }
                break;
            case Enter:
                return current_row;
                break;
        }
    }
}


size_t find_max_msg_len(char **msgs, char *title, size_t num_msgs) {
    size_t longest_len = strlen(title);
    size_t current_len;
    for (int i = 0; i < num_msgs; ++i) {
        if ((current_len = strlen(msgs[i])) > longest_len) {
            longest_len = current_len;
        }
    }
    return longest_len;
}

void print_title(char *title, size_t table_size) {
    size_t title_len = strlen(title);

    fputs("  "MODE_DRAW"l", stdout);
    for (int i = 0; i < (table_size + 2); ++i) {
        putchar('q');
    }
    fputs("k\n  x "MODE_DRAW_RESET, stdout);

    fputs(title, stdout);
    for (int i = strlen(title); i < (table_size + 1); ++i) {
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
    fputs(row, stdout);

    for (int i = strlen(row); i < (len + 1); ++i) {
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