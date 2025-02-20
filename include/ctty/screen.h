// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#ifndef SCREEN_H
#define SCREEN_H

#ifdef __cplusplus
extern "C" {
#endif


void clear_screen(void);

/**
 * Function name: resize_screen
 * Date created: 7 Nov 2024
 * Date last modified: 7 Nov 2024
 * Description: Resizes terminal screen to be `lines` by `cols`.
 * Inputs: 
 * `lines` : The number of lines you want the terminal to have.
 * `cols` : The number of columns you want the terminal to have.
 * Outputs: none
 */
void resize_screen(int lines, int cols);

#ifdef __cplusplus
}
#endif

#endif
