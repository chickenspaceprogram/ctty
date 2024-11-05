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

size_t menu(Option *options, unsigned char *title, size_t num_options);