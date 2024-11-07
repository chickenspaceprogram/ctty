#ifndef MENU_MENU_H
#define MENU_MENU_H
#include <stddef.h>
#include <string.h>
#include "../ansi/text-modes.h"
#include "../ansi/cursor.h"
#include "../keypress/keyselect.h"
#include "../keypress/keypress-codes.h"
#include <stdio.h>

typedef struct {
    unsigned char *msg;
    unsigned char *sequence;
} Option;

/**
 * Function name: 
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: 
 * Inputs: 
 * Outputs: 
 */
size_t menu(Option *options, unsigned char *title, size_t num_options);

#endif