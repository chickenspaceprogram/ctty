#ifndef KEYCODES_H
#define KEYCODES_H

#define CTTY_ESC        {"\x1B", 1}

#ifdef _WIN32

#define CTTY_UP         {"\xE0H", 2}
#define CTTY_DOWN       {"\xE0P", 2}
#define CTTY_LEFT       {"\xE0K", 2}
#define CTTY_RIGHT      {"\xE0M", 2}

#define CTTY_DEL        {"\xE0S", 2}

#else

#define CTTY_UP         {"\x1B[A", 3}
#define CTTY_DOWN       {"\x1B[B", 3}
#define CTTY_LEFT       {"\x1B[D", 3}
#define CTTY_RIGHT      {"\x1B[C", 3}

#define CTTY_DEL        {"\x1B[3~", 4}

#endif
#endif