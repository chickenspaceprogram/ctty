// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

/**
 * A file providing preprocessor macros for common keypresses.
 * This is not all-inclusive, but it has all of the macros that I personally need and I'm not going to bother adding more.
 * Feel free to submit a PR adding more keycodes if you want, though!
 */

#ifndef KEYPRESS_CODES_H
#define KEYPRESS_CODES_H

#ifdef __cplusplus
extern "C" {
#endif

#define CTTY_ESC        {(unsigned const char *)"\x1B", 1}

#define CTTY_a          {(unsigned const char *)"a", 1}
#define CTTY_b          {(unsigned const char *)"b", 1}
#define CTTY_c          {(unsigned const char *)"c", 1}
#define CTTY_d          {(unsigned const char *)"d", 1}
#define CTTY_e          {(unsigned const char *)"e", 1}
#define CTTY_f          {(unsigned const char *)"f", 1}
#define CTTY_g          {(unsigned const char *)"g", 1}
#define CTTY_h          {(unsigned const char *)"h", 1}
#define CTTY_i          {(unsigned const char *)"i", 1}
#define CTTY_j          {(unsigned const char *)"j", 1}
#define CTTY_k          {(unsigned const char *)"k", 1}

#define CTTY_1          {(unsigned const char *)"1", 1}
#define CTTY_2          {(unsigned const char *)"2", 1}
#define CTTY_3          {(unsigned const char *)"3", 1}
#define CTTY_4          {(unsigned const char *)"4", 1}
#define CTTY_5          {(unsigned const char *)"5", 1}
#define CTTY_6          {(unsigned const char *)"6", 1}
#define CTTY_7          {(unsigned const char *)"7", 1}
#define CTTY_8          {(unsigned const char *)"8", 1}
#define CTTY_9          {(unsigned const char *)"9", 1}
#define CTTY_0          {(unsigned const char *)"0", 1}

#define CTTY_SPACE      {(unsigned const char *)" ", 1}


#ifdef _WIN32

#define CTTY_UP         {(unsigned const char *)"\xE0H", 2} // up arrow key
#define CTTY_DOWN       {(unsigned const char *)"\xE0P", 2} // down arrow key
#define CTTY_LEFT       {(unsigned const char *)"\xE0K", 2} // left arrow key
#define CTTY_RIGHT      {(unsigned const char *)"\xE0M", 2} // right arrow key
#define CTTY_ENTER      {(unsigned const char *)"\r", 1} // [Enter] key

#define CTTY_DEL        {(unsigned const char *)"\xE0S", 2}

#else

#define CTTY_UP         {(unsigned const char *)"\x1B[A", 3} // up arrow key
#define CTTY_DOWN       {(unsigned const char *)"\x1B[B", 3} // down arrow key
#define CTTY_LEFT       {(unsigned const char *)"\x1B[D", 3} // left arrow key
#define CTTY_RIGHT      {(unsigned const char *)"\x1B[C", 3} // right arrow key
#define CTTY_ENTER      {(unsigned const char *)"\n", 1} // [Enter] key

#define CTTY_DEL        {(unsigned const char *)"\x1B[3~", 4}

#endif

#ifdef __cplusplus
}
#endif

#endif
