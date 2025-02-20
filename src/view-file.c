// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <stdio.h>
#include <stddef.h>
#include <string.h>

#include <ctty/view-file.h>
#include <ctty/keypress.h>
#include <ctty/screen.h>
#include <ctty/cursor.h>

#define PAGE_SIZE 4096

//#ifdef _WIN32


void print_file(char *filename, int should_clear_screen) {

	// opening file, ensuring it is non-null
	FILE* input = fopen(filename, "r");
	if (input == NULL) {
		printf("An error occurred while loading the file `%s`.\n\nPress any key to continue . . . ", filename);
		fputs(CURSOR_OFF, stdout);
		PAUSE();
		fputs(CURSOR_ON, stdout);
		return;
	}
	
	// allocating it on the stack is probably bad practice since the buffer's relatively large, but I'm lazy and this worked
	char buffer[PAGE_SIZE + 1]; 
	memset(buffer, '\0', PAGE_SIZE + 1);
	
	// if we want to clear the screen, do it now after everything's been allocated to minimize time where screen is blank
	if (should_clear_screen) {
		clear_screen(); // the option to not clear the screen is not used, but I want to make this function more general
	}

	do {
		fread(buffer, sizeof(char), PAGE_SIZE, input);

		fputs(buffer, stdout);
		if (!feof(input)) {
			memset(buffer, '\0', PAGE_SIZE);
		}
	} while (!feof(input)); // keep looping until we reach EOF

	// closing file
	fclose(input);
}
