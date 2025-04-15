# MyOS

MyOS is a lightweight, console-based operating system shell written in C++. It is designed for educational purposes to demonstrate basic file operations and provide insight into OS concepts.

## Features

- **create file**: Create a new file while automatically creating any missing parent directories.
- **list**: Display files and directories in a specified path.
- **rename**: Change the name of a file.
- **move**: Move files between directories.
- **delete**: Remove files.
- **copy**: Copy files with overwrite support.

## Requirements

- **Compiler**: A modern C++17 compiler (GCC, Clang, etc.)
- **CMake**: Version 3.10 or higher
- **Platform**: macOS, Linux, or Windows

## Building the Project
```bash
mkdir build
cd build
cmake ..
cmake --build .
```

## Usage
From within the `build` directory, run:
```
./MyOS
```
- **`list [path]`**  
  Lists files in the specified directory (defaults to the current directory).

- **`rename <oldname> <newname>`**  
  Renames a file.

- **`move <source> <destination>`**  
  Moves a file to a new location.

- **`delete <filename>`**  
  Deletes a file.

- **`copy <source> <destination>`**  
  Copies a file (with overwrite support).

- **`create file <filename>`**  
  Creates a new file (automatically creating any missing parent directories).

- **`exit`**  
  Exits the shell.

