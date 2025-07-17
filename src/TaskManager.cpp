#include "TaskManager.hpp"
#include "PlatformUtils.hpp"
#include <dlfcn.h>            // For dlopen, dlsym
#include <iostream>           // For std::cerr

// Refresh task list using PlatformUtils
void TaskManager::refreshTasks() {
    tasks = PlatformUtils::listRunningTasks();
}

// Dynamically load a plugin shared library
void TaskManager::loadPlugin(const std::string& path) {
    // Open shared library (.so)
    void* handle = dlopen(path.c_str(), RTLD_LAZY);
    if (!handle) {
        std::cerr << "Failed to load plugin\n";
        return;
    }

    // Get function pointers for create_plugin and destroy_plugin
    auto create = (PluginInterface*(*)())dlsym(handle, "create_plugin");
    auto destroy = (void(*)(PluginInterface*))dlsym(handle, "destroy_plugin");
    if (!create || !destroy) {
        std::cerr << "Invalid plugin\n";
        return;
    }

    // Create plugin instance and store in vector with custom deleter
    plugins.emplace_back(create(), destroy);
}

// Run all loaded plugins on each task
void TaskManager::runAnalysis() {
    for (auto& t : tasks) {            // For each task
        for (auto& p : plugins) {      // For each plugin
            p->analyzeTask(t);         // Let plugin analyze task
        }
    }
}
