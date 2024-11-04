#ifndef CTTY_MENU_MENU_H
#define CTTY_MENU_MENU_H

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include "../keyselect.h"
#include "../keypress-codes.h"
#include "../ansi/text-modes.h"
#include "../ansi/cursor.h"

typedef struct {
    char *msg;
    char *selection_seq;
    int is_valid;
} Option;

typedef struct {
    char *title;
    Option *options;
    size_t num_options;
} Menu;

size_t select_menu_option(Menu menu, size_t num_options);

void print_menu(Menu menu, size_t *row_offsets, size_t num_options, size_t menu_len);

size_t find_menu_len(Menu menu, size_t *options_len);

// returns number of rows
size_t find_row_nums(Menu menu, size_t *row_nums);

void fill_with_value(size_t *arr, size_t value, size_t len);

void print_title(char *title, size_t table_size);

#endif