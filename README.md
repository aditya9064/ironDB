# IronDB

A small database project I'm building in C++ to learn how databases work.

## v0.2

The menu now takes input and keeps running until you enter 0. It handles invalid input too. The table options only print messages for now, and nothing is saved yet.

## Run it

You need CMake 3.20+ and a C++20 compiler.

```sh
cmake -S . -B build
cmake --build build
./build/IronDB
```

Next up: add basic table creation.