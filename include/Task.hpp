#pragma once                 // Ensure this header is included only once by the compiler
#include <string>            // We need std::string to store process names

// This class represents a single process (task) in the system
class Task {
public:
    // Constructor takes a PID and a process name
    Task(int pid, std::string name)
        : pid(pid), name(std::move(name)) {}  // store values (move name for efficiency)

    // Getter for process ID
    int getPid() const { return pid; }

    // Getter for process name
    const std::string& getName() const { return name; }

private:
    int pid;                // Process ID
    std::string name;       // Process name (like "bash", "firefox", etc.)
};
