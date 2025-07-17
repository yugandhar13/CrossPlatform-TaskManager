//TITLE-Cross‑Platform Task Manager with Plugin System (C++)

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


//Order to understand the project

// main.cpp
// TaskManager.hpp
// TaskManager.cpp
// Task.hpp
// PlatformUtils.hpp
// PlatformUtils.cpp
// PluginInterface.hpp
// plugins/sample_plugin/SamplePlugin.cpp
// CMakeLists.txt