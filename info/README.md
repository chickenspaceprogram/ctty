# ctty

A simple cross-platform terminal graphics library, written in C.

To use this, simply copy the files in src/ into your current project. Ensure that they're all in the same directory. You can omit any of them that you won't use, with the exception that `screen.h` and `keyselect.h` require `keypress.h`, and all the `.h` files require their corresponding `.c` files.

This project provides functions and preprocessor macros that make dealing with terminal graphics across different platforms less painful.
It's not all-inclusive, and there's definitely things I haven't added.
However, half the purpose of this library was to facilitate code reuse when completing programming assignments for a CS course I'm taking.

`escape-codes.h` : Provides macros for some common ANSI escape codes

`screen.h` : Provides macros to clear the screen and wait for a user's next keypress. **Dependency:** `keypress.h`

`keypress.h` : Provides functions and macros to facilitate detecting keypresses without waiting for the user to press [Enter].

`keyselect.h` : Provides a simple way to detect and return only certain keypresses. **Dependency:** `keypress.h`

`keycodes.h` : A header file containing preprocessor macros for common keycodes.

`info/main.c` : An example program showing how to use ctty. This program waits for the user to press 'a', 's', 'd', 'f', or one of the arrow keys, and then prints the index of that key in the array passed to keyselect.
