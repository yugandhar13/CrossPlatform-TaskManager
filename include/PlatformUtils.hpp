#pragma once
#include "Task.hpp"          // We return a vector of Task objects
#include <vector>            // Need std::vector

namespace PlatformUtils {
    // Returns a vector of all running tasks (scans /proc)
    std::vector<Task> listRunningTasks();

    // Tries to kill a process by PID, returns true if successful
    bool killTask(int pid);
}
