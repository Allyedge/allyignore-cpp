# Allyignore-CPP

[![GitHub License](https://img.shields.io/github/license/Allyedge/allyignore-cpp)](https://github.com/Allyedge/allyignore-cpp)

A tool that finds and removes unnecessary lines from `.gitignore` files.

## C++

This is the C++ rewrite of Allyignore, mostly for practice. The original version was written in Go. You can find it at https://github.com/Allyedge/allyignore.

## Usage

```sh
# CMake.
> cmake .

# Compile Allyignore.
> make all

# Run Allyignore.
> allyignore

# Run Allyignore but don't keep comments and empty lines.
> allyignore --nokeep

# Get help with the commands and options.
> allyignore --help

# Get the version number of Allyignore.
> allyignore --version
```
