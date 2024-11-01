# ctty v2.0.2

A simple cross-platform terminal graphics library, written in C.

Developer: [chickenspaceprogram](https://github.com/chickenspaceprogram)

Project link: [ctty](https://github.com/chickenspaceprogram/ctty)


To use this library, simply include this repository in your project as a git submodule (or just copy-paste all the files into a folder in your project). 

How you go about configuring a build system for this is left up to you. With a decent Makefile it's pretty easy (that's what I use). With something like Microsoft Visual Studio, it's probably a bit more annoying. You'll want to include the whole `ctty` directory in your project, so feel free to google how to do that.

This project provides functions and preprocessor macros that make dealing with terminal graphics across different platforms less painful.
It's not all-inclusive, and there's definitely things I haven't added.
It also hasn't yet been tested thoroughly, so please keep an eye out for bugs and open a GitHub issue if you find any.

Half the purpose of this library was to facilitate code reuse when completing assignments for a CS course I'm taking, so I'm more or less fine with this being a bit rough around the edges.

### ANSI sequences

`ansi/` : A subfolder with header files making ANSI escape sequences easier to use.

`ansi/colors.h` : Provides macros to set text and background color.

`ansi/cursor.h` : Provides macros for handling cursor position. **Dependency:** `keypress.h`

`ansi/erase.h` : Provides macros for erasing part or all of the screen.

`ansi/text-modes.h` : Provides macros for changing the text mode to and from bold, underline, and other modes.

### Other stuff

`screen.h` : Provides macros to clear the screen and wait for a user's next keypress. **Dependency:** `keypress.h`

`keypress.h` : Provides functions and macros to facilitate detecting keypresses without waiting for the user to press [Enter].

`keyselect.h` : Provides a simple way to detect and return only certain keypresses. **Dependency:** `keypress.h`

`keycodes.h` : A header file containing preprocessor macros for common keycodes.
