#ifndef KEYPRESS_H
#define KEYPRESS_H

#include <stdio.h>

#ifdef _WIN32
#include <conio.h>

/**
 * Macro name: GETCH
 * Date created: 10/19/2024
 * Date last modified: 10/25/2024
 * Description: Gets a single keypress from the user without waiting or echoing the inputs to the terminal.
 *              Does not detect and handle escape sequences (like arrow keys)
 * Inputs: none
 * Outputs: The user's keypress
 */
#define GETCH() _getch()

#define NEWLINE '\r'

#else
#include <termios.h>
#include <unistd.h>
/**
 * Function name: unix_getch
 * Date created: 10/19/2024
 * Date last modified: 10/22/2024
 * Description: Gets a character directly from stdin without buffering or echoing it to the terminal.
 *              Does not detect and handle escape sequences (like arrow keys)
 * Inputs: none
 * Outputs: The character that was entered.
 */
int unix_getch(void);

/**
 * Macro name: GETCH
 * Date created: 10/19/2024
 * Date last modified: 10/22/2024
 * Description: Gets a character directly from stdin without buffering or echoing it to the terminal.
 *              Does not detect and handle escape sequences (like arrow keys)
 * Inputs: none
 * Outputs: The character that was entered.
 */
#define GETCH() unix_getch()

#define NEWLINE '\n'

#endif

#endif