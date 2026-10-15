# IronDB

A small database project I'm building in C++ to learn how databases work.

## v0.1

Right now it just prints a menu and exits. Creating tables, adding rows, and showing data don't work yet.

## Run it

You need CMake 3.20+ and a C++20 compiler.

```sh
cmake -S . -B build
cmake --build build
./build/IronDB
```

Next up: make the menu take input.