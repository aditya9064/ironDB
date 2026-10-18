# Notes

## v0.3

- Added Column and Table classes in their own .h and .cpp files.
- Columns store values in a pointer array that grows when full.
- Adding or updating a row changes every column so they stay the same length.
- Made the menu options work and added Update Row.

## v0.2

- Made the menu repeat until the user enters 0.
- Added messages for each menu option.
- Added checks for invalid input and stopped the loop when input ends.
- Added basic comments. Table features still don't work yet.

## v0.1

- Set up the C++ project with CMake.
- Added the IronDB title and a basic menu.
- The menu only prints for now. Nothing is saved yet.