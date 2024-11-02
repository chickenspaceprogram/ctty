#ifndef ANSI_COLORS_H
#define ANSI_COLORS_H

#include <stdio.h>

#ifndef RESET_GRAPHICS // only defining RESET_GRAPHICS if it has not already been defined
#define RESET_GRAPHICS              "\x1B[0m" // resets graphics
#endif


/* Reset Colors to Defaults */
#define BG_DEFAULT                  "\x1B[49m"
#define FG_DEFAULT                  "\x1B[39m"

/* Normal Colors (background) */
#define BG_BLACK                    "\x1B[40m"
#define BG_RED                      "\x1B[41m"
#define BG_GREEN                    "\x1B[42m"
#define BG_YELLOW                   "\x1B[43m"
#define BG_BLUE                     "\x1B[44m"
#define BG_MAGENTA                  "\x1B[45m"
#define BG_CYAN                     "\x1B[46m"
#define BG_WHITE                    "\x1B[47m"

/* Normal Colors (foreground) */
#define FG_BLACK                    "\x1B[30m"
#define FG_RED                      "\x1B[31m"
#define FG_GREEN                    "\x1B[32m"
#define FG_YELLOW                   "\x1B[33m"
#define FG_BLUE                     "\x1B[34m"
#define FG_MAGENTA                  "\x1B[35m"
#define FG_CYAN                     "\x1B[36m"
#define FG_WHITE                    "\x1B[37m"

/* Bright Colors (background) */
#define BG_BLACK_BRIGHT             "\x1B[100m"
#define BG_RED_BRIGHT               "\x1B[101m"
#define BG_GREEN_BRIGHT             "\x1B[102m"
#define BG_YELLOW_BRIGHT            "\x1B[103m"
#define BG_BLUE_BRIGHT              "\x1B[104m"
#define BG_MAGENTA_BRIGHT           "\x1B[105m"
#define BG_CYAN_BRIGHT              "\x1B[106m"
#define BG_WHITE_BRIGHT             "\x1B[107m"

/* Bright Colors (foreground) */
#define FG_BLACK_BRIGHT             "\x1B[30m"
#define FG_RED_BRIGHT               "\x1B[31m"
#define FG_GREEN_BRIGHT             "\x1B[32m"
#define FG_YELLOW_BRIGHT            "\x1B[33m"
#define FG_BLUE_BRIGHT              "\x1B[34m"
#define FG_MAGENTA_BRIGHT           "\x1B[35m"
#define FG_CYAN_BRIGHT              "\x1B[36m"
#define FG_WHITE_BRIGHT             "\x1B[37m"

/* RGB Colors */
#define FG_RGB(R, G, B)             printf("\x1B[38;2;%d;%d;%dm", R, G, B)
#define BG_RGB(R, G, B)             printf("\x1B[48;2;%d;%d;%dm", R, G, B)

#endif
