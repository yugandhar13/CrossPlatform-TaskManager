# Cross-Platform Task Manager with Plugin System (C++)

A modular process-monitoring tool with dynamic plugins.

## Features
- Lists running processes (via /proc on Linux)
- Loads plugins dynamically at runtime
- Extensible architecture (easy to add more plugins)

## Build Instructions (Linux)
```bash
mkdir build && cd build
cmake ..
make
./TaskManager
