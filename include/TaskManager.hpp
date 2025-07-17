#pragma once
#include <vector>                             // For std::vector
#include <memory>                             // For std::unique_ptr
#include <string>                             // For std::string
#include "Task.hpp"                           // Task representation
#include "PluginInterface.hpp"                // Plugins interface

// Manages processes and plugins
class TaskManager {
public:
    void refreshTasks();                      // Refresh list of tasks
    void loadPlugin(const std::string& path); // Load a plugin .so from disk
    void runAnalysis();                       // Run all plugins on all tasks

private:
    std::vector<Task> tasks;                  // Current list of running tasks
    // List of loaded plugins (unique_ptr with custom deleter)
    std::vector<std::unique_ptr<PluginInterface, void(*)(PluginInterface*)>> plugins;
};
