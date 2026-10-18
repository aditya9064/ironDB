# IronDB

A small database project I'm building in C++ to learn how databases work.

## v0.3

You can now create tables, add rows, update rows, and show or list tables. Each table stores its data in columns, and adding or updating a row changes every column at once. Data is only kept while the program runs.

## Run it

You need CMake 3.20+ and a C++20 compiler.

```sh
cmake -S . -B build
cmake --build build
./build/IronDB
```

Next up: save tables to a file.