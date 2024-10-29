#include "keypress.h"

/**
 * Function name: select_char
 * Date created: 10/29/2024
 * Date last modified: 10/29/2024
 * Description: Waits until the user enters a character or escape sequence in `char_sequences`, then returns the index of the selected sequence.
 * Inputs: 
 * `char_sequences` :   An array of char arrays of variable length that contain the sequences to search for.
 *                      The arrays in this array are *not* assumed to be null-terminated, since some escape sequences on some platforms contain the null character.
 * `sequence_lengths` : The length of each char array in char_sequences.
 * `num_sequences` : The number of sequences in `char_sequences`.
 * Outputs: The index of the sequence that was entered.
 */
int select_char(const char **char_sequences, int *sequence_lengths, int num_sequences);

/**
 * Function name: check_char
 * Date created: 10/29/2024
 * Date last modified: 10/29/2024
 * Description: 
 * Inputs: 
 * `char_sequences` :   An array of char arrays of variable length that contain the sequences to search for.
 *                      The arrays in this array are *not* assumed to be null-terminated, since some escape sequences on some platforms contain the null character.
 * `sequence_lengths` : The length of each char array in char_sequences.
 * Outputs: The index of the sequence that was entered, or -1 if the sequence was invalid.
 */
int check_char(const char **char_sequences, int *sequence_lengths, int num_sequences);

