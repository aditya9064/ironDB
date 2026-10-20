# Development log

## v0.3

- Split the code into Column and Table classes with .h and .cpp files.
- Used new[] and delete[] to make arrays that can grow.
- Learned that a class that deletes memory should not be copied, so I turned copying off.
- Freed every table when the program exits.
- Next I want to save tables to a file.

## v0.2

- Added a loop so the menu stays open.
- Used a switch for the menu choices.
- Learned how to clear bad input with cin.clear() and cin.ignore().
- Added a check so the program stops if input ends.
- Next I want to make Create Table actually do something.

# IronDB Development Log

## Version 0.2 - Interactive Menu

### What I added
- A repeating menu using a while loop.
- A switch statement to handle menu options.
- Basic error handling for nonnumeric input.

### Why I made these changes
The previous program only displayed a menu and exited.
The new version allows users to select operations repeatedly
without restarting the program.

### Concepts used
- Variables and initialization
- While loops
- Switch statements
- Standard input and output
- Input stream error handling

### Limitations
- Database operations are placeholders.
- No tables or records are stored yet.
- Input ending now stops the menu loop.
