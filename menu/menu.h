#ifndef CTTY_MENU_MENU_H
#define CTTY_MENU_MENU_H

#include <stddef.h>
#include <string.h>

typedef struct {
    char *msg;
    char *selection_seq;
    int is_valid;
} Option;

typedef struct {
    char *title;
    Option *options;
    size_t num_options
} Menu;

size_t find_longest_len(Menu menu);

#endif