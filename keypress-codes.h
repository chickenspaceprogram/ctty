/**
 * A file providing preprocessor macros for common keypresses.
 * This is not all-inclusive, but it has all of the macros that I personally need and I'm not going to bother adding more.
 * Feel free to submit a PR adding more keycodes if you want, though!
 */

#ifndef KEYPRESS_CODES_H
#define KEYPRESS_CODES_H

#define CTTY_ESC        {"\x1B", 1}

#define CTTY_a          {"a", 1}
#define CTTY_b          {"b", 1}
#define CTTY_c          {"c", 1}
#define CTTY_d          {"d", 1}
#define CTTY_e          {"e", 1}
#define CTTY_f          {"f", 1}
#define CTTY_g          {"g", 1}
#define CTTY_h          {"h", 1}
#define CTTY_i          {"i", 1}
#define CTTY_j          {"j", 1}

#define CTTY_1          {"1", 1}
#define CTTY_2          {"2", 1}
#define CTTY_3          {"3", 1}
#define CTTY_4          {"4", 1}
#define CTTY_5          {"5", 1}
#define CTTY_6          {"6", 1}
#define CTTY_7          {"7", 1}
#define CTTY_8          {"8", 1}
#define CTTY_9          {"9", 1}
#define CTTY_0          {"0", 1}


#ifdef _WIN32

#define CTTY_UP         {"\xE0H", 2} // up arrow key
#define CTTY_DOWN       {"\xE0P", 2} // down arrow key
#define CTTY_LEFT       {"\xE0K", 2} // left arrow key
#define CTTY_RIGHT      {"\xE0M", 2} // right arrow key
#define CTTY_ENTER      {"\r", 1} // [Enter] key

#define CTTY_DEL        {"\xE0S", 2}

#else

#define CTTY_UP         {"\x1B[A", 3} // up arrow key
#define CTTY_DOWN       {"\x1B[B", 3} // down arrow key
#define CTTY_LEFT       {"\x1B[D", 3} // left arrow key
#define CTTY_RIGHT      {"\x1B[C", 3} // right arrow key
#define CTTY_ENTER      {"\n", 1} // [Enter] key

#define CTTY_DEL        {"\x1B[3~", 4}

#endif
#endif
