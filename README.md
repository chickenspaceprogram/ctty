# ctty v5.0.10

A simple cross-platform terminal graphics library, written in C.

Developer: [chickenspaceprogram](https://github.com/chickenspaceprogram)

Project link: [ctty](https://github.com/chickenspaceprogram/ctty)

This project provides functions and preprocessor macros that make dealing with terminal graphics across different platforms less painful.
It's not all-inclusive, and there's definitely things I haven't added.
It also hasn't yet been tested thoroughly, so please keep an eye out for bugs and open a GitHub issue if you find any.

To use this library, simply include this repository in your project as a git submodule (or just copy-paste all the files into a folder in your project). Then, you can use CMake to link the library. Just use `add_subdirectory()` to add `ctty` to your project, and `target_link_libraries()` to link it. If you encounter issues, please make a GitHub issue. I'm not the most experienced with CMake so it's possible I messed something up when configuring it.

### ANSI sequences

`ansi/colors.h` : Provides macros and functions to set text and background color.

`ansi/cursor.h` : Provides macros for handling cursor position.

`ansi/erase.h` : Provides macros for erasing part or all of the screen.

`ansi/text-modes.h` : Provides macros for changing the text mode to and from bold, underline, and other modes.

### Keypress detection

`keypress/keypress.h` : Provides macros to detect the user's keypress immediately, without echoing or buffering their input.

`keypress/keyselect.h` : Provides a function to detect and accept only certain keypresses.

`keypress/keypress-codes.h` : Provides macros to make interacting with `keyselect.h` less painful.

### Nice menus

`menu.h` : Displays a nice menu and allows the user to select their desired option using the arrow keys or using user-defined hotkeys.

### Other stuff

`screen/screen.h` : Provides macros to clear the screen and wait for a user's next keypress.
