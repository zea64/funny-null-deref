# Funny Null Dereference
It's funny

## What?
This makes Linux map a page at `0x0` for us, so we can write to NULL without segfaulting.

The C standard says that NULL pointers are always invalid, and gcc and clang both take advantage of that to do surprising things, like removing NULL checks if you dereferenced the pointer (because surely your program would've segfaulted when you did that). For the love of god, do not do this in real code.

## Why?
Funny.
