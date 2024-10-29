# ctty

A simple cross-platform terminal graphics library, written in C.

This project provides preprocessor macros that make dealing with terminal graphics across different platforms less painful.
It's not all-inclusive, and there's definitely things I haven't added.
However, I'm mostly fine with that since half the purpose of this library was to facilitate code reuse when completing programming assignments for a CS course I'm taking.

Please excuse the commenting scheme, the professor for this class requires what I'd personally deem an excessive amount of comments.

`escape-codes.h` : Provides macros for some common ANSI escape codes

`screen.h` : Provides macros to clear the screen and wait for a user's next keypress. **Dependency:** `keypress.h`

`keypress.h` : Provides functions and macros to facilitate detecting keypresses without waiting for the user to press [Enter].

`keyselect.h` : Provides a simple way to detect and return only certain keypresses.

`keycodes.h` : A header file containing preprocessor macros for common keycodes.