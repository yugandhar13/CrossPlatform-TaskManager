#include "PlatformUtils.hpp"
#include <dirent.h>          // For reading directories (opendir, readdir)
#include <signal.h>          // For kill() system call
#include <fstream>           // For reading files like /proc/[pid]/comm
#include <cstdlib>           // For atoi()

// Scan /proc to build a list of running tasks
std::vector<Task> PlatformUtils::listRunningTasks() {
    std::vector<Task> tasks;           // Result vector

    DIR* dir = opendir("/proc");       // Open the /proc directory
    if (!dir) return tasks;            // If we can't open it, return empty

    struct dirent* entry;
    while ((entry = readdir(dir)) != nullptr) {   // Iterate over directory entries
        if (entry->d_type == DT_DIR) {            // If entry is a directory
            int pid = atoi(entry->d_name);        // Convert name to number
            if (pid > 0) {                        // Only consider numeric directories (PIDs)
                // Build path to the process name file
                std::string cmdPath = std::string("/proc/") + entry->d_name + "/comm";
                std::ifstream cmdFile(cmdPath);   // Open it
                std::string name;
                if (cmdFile.good()) {             // If file exists
                    std::getline(cmdFile, name);  // Read first line (process name)
                    tasks.emplace_back(pid, name);// Add Task object to vector
                }
            }
        }
    }
    closedir(dir);                // Close /proc directory
    return tasks;                 // Return the list
}

// Kill a process by sending SIGTERM
bool PlatformUtils::killTask(int pid) {
    return (kill(pid, SIGTERM) == 0);  // Return true if system call succeeded
}
