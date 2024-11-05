#include <stddef.h>
#include <string.h>
#include "../ansi/text-modes.h"
#include "../ansi/cursor.h"
#include "../keypress/keyselect.h"
#include "../keypress/keypress-codes.h"
#include <stdio.h>

size_t menu(char **options, char *title, size_t num_options);