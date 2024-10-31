#ifndef SCREEN_H
#define SCREEN_H

#include <stdio.h>
#include <stdlib.h>
#include "keypress.h"

#ifdef _WIN32

/**
 * Macro name: CLEAR_SCREEN
 * Date created: 10/19/2024
 * Date last modified: 10/25/2024
 * Description: Clears the screen.
 * Inputs: none
 * Outputs: none
 */
#define CLEAR_SCREEN() system("cls")

#else

/**
 * Macro name: CLEAR_SCREEN
 * Date created: 10/19/2024
 * Date last modified: 10/19/2024
 * Description: Clears the screen.
 * Inputs: none
 * Outputs: none
 */
#define CLEAR_SCREEN() system("clear")

#endif

/**
 * Macro name: PAUSE
 * Date created: 10/24/2024
 * Date last modified: 10/24/2024
 * Description: Pauses the program's execution until the user presses any key.
 * Inputs: none
 * Outputs: none, typecasts to void to make it clear that this is solely for pausing
 */
#define PAUSE() (void) GETCH()

#endif
