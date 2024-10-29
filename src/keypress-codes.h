/**
 * A file providing preprocessor macros for common keypresses.
 * This is not all-inclusive, but it has all of the macros that I personally need and I'm not going to bother adding more.
 * Feel free to submit a PR adding more keycodes if you want, though!
 */

#ifndef KEYPRESS_CODES_H
#define KEYPRESS_CODES_H

#define CTTY_ESC        {"\x1B", 1}

#ifdef _WIN32

#define CTTY_UP         {"\xE0H", 2} // up arrow key
#define CTTY_DOWN       {"\xE0P", 2} // down arrow key
#define CTTY_LEFT       {"\xE0K", 2} // left arrow key
#define CTTY_RIGHT      {"\xE0M", 2} // right arrow key

#define CTTY_DEL        {"\xE0S", 2}

#else

#define CTTY_UP         {"\x1B[A", 3} // up arrow key
#define CTTY_DOWN       {"\x1B[B", 3} // down arrow key
#define CTTY_LEFT       {"\x1B[D", 3} // left arrow key
#define CTTY_RIGHT      {"\x1B[C", 3} // right arrow key

#define CTTY_DEL        {"\x1B[3~", 4}

#endif
#endif