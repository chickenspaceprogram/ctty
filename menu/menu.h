// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef MENU_MENU_H
#define MENU_MENU_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <string.h>
#include "../ansi/text-modes.h"
#include "../ansi/cursor.h"
#include "../keypress/keyselect.h"
#include "../keypress/keypress-codes.h"
#include <stdio.h>
#include <stdbool.h>

// `msg` is the message to be displayed for the option
// `sequence` is the sequence of keypresses that will select the option
typedef struct option {
    unsigned char *msg;
    unsigned char *sequence;
} Option;

typedef struct selections {
    bool *selections;
    size_t num_selections
} Selections;

/**
 * Function name: menu
 * Date created: 5 Nov 2024
 * Date last modified: 5 Nov 2024
 * Description: Creates a nice menu, and allows the user to select one option from it.
 * Inputs: 
 * `options` : An array containing all of the possible options the user could select.
 * `title` : The title of the menu.
 * `num_options` : The number of options
 * Outputs: The index of the option that the user selected.
 */
size_t menu(Option *options, char *title, size_t num_options);

/**
 * Function name: menu
 * Date created: 20 Nov 2024
 * Date last modified: 21 Nov 2024
 * Description: Creates a nice menu, and allows the user to select multiple options from it.
 * Inputs: 
 * `options` : An array containing all of the possible options the user could select.
 * `title` : The title of the menu.
 * `num_options` : The number of options
 * `max_num_selections` : The maximum number of items the user can select at once.
 * Outputs: 
 * `selections` : An array of booleans. If `selections[i] == true`, then the option was selected. If `selections[i]` == false, the option was not selected.
 */
void multimenu(Option *options, char *title, size_t num_options, bool *selections, size_t max_num_selections);

#ifdef __cplusplus
}
#endif

#endif