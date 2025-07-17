#include "TaskManager.hpp"    // To use TaskManager
#include <iostream>           // For output

int main() {
    TaskManager tm;           // Create manager

    // Load the plugin shared object from current folder
    tm.loadPlugin("./libsample_plugin.so");

    // Refresh task list (reads /proc)
    tm.refreshTasks();

    // Run plugin analysis on each task
    tm.runAnalysis();

    return 0;                 // Exit
}
