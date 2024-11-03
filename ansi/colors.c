#include "colors.h"

static int round_double(double num);

static int rescale_color(unsigned char color);

void set_color(Color foreground, Color background) {
    printf("\x1B[%d;%dm", (int)foreground, (int)background + 10);
}

void set_color_rgb(RGB foreground, RGB background) {
    // got this algorithm straight from Wikipedia
    int foreground_conv = 16 + 36 * rescale_color(foreground.r) + 6 * rescale_color(foreground.g) + rescale_color(foreground.b);
    int background_conv = 16 + 36 * rescale_color(background.r) + 6 * rescale_color(background.g) + rescale_color(background.b);
    printf("\x1B[38;5;%d;48;5;%dm", foreground_conv, background_conv);
}

void set_color_rgb_24bit(RGB foreground, RGB background) {
    printf("\x1B[38;2;%d;%d;%d;48;2;%d;%d;%dm", (int)foreground.r, (int)foreground.g, (int)foreground.b, (int)background.r, (int)background.g, (int)background.b);
}

void set_color_256(unsigned char foreground, unsigned char background) {
    printf("\x1B[38;5;%d;48;5;%dm", (int)foreground, (int)background);
}

int round_double(double num) {
    return (int) num + 0.5; // pretty cursed and only works for positive numbers but
}

int rescale_color(unsigned char color) {
    return (int)((double) color * 6 / 256 - 0.5); // converts the color that ranges 0-256 into one that ranges 1-6, then subtracts 0.5 and typecasts to int, essentially subtracting 1 and rounding to the nearest int from 0-5
}