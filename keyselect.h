#ifndef KEYSELECT_H
#define KEYSELECT_H
#include "keypress.h"
#include <stdlib.h>

/**
 * Struct name: sequence
 * Date created: 10/29/2024
 * Date last modified: 10/29/2024
 * Description: Contains the characters in a escape sequence.
 * `chars` : An array containing the sequence of characters in the sequence.
 * `len` : The length of the sequence. For example, "abcd" has a length of 4.
 */
typedef struct sequence {
    unsigned char *chars; // An array containing the sequence of characters in the sequence.
    int len; // The length of the sequence. For example, "abcd" has a length of 4.
} sequence;

/**
 * Function name: select_char
 * Date created: 10/29/2024
 * Date last modified: 10/29/2024
 * Description: Waits until the user enters a character or escape sequence in `char_sequences`, then returns the index of the selected sequence.
 * Inputs: 
 * `sequences` : An array containing sequence structs for the escape sequences to be entered.
 * `num_sequences` : The number of sequences in `char_sequences`.
 * Outputs: The index of the sequence that was entered.
 */
int select_char(sequence *sequences, int num_sequences);

/**
 * Function name: check_char
 * Date created: 10/29/2024
 * Date last modified: 10/29/2024
 * Description: 
 * Inputs: 
 * `sequences` : An array containing sequence structs for the escape sequences to be entered.
 * `num_sequences` : The number of sequences in `char_sequences`.
 * Outputs: The index of the sequence that was entered, or -1 if the sequence was invalid.
 */
int check_char(sequence *sequences, int num_sequences);

#endif