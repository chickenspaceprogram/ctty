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
size_t menu(Option *options, char *title, size_t num_options);

#ifdef __cplusplus
}
#endif

#endif