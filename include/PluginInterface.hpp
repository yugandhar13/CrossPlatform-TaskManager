#pragma once
#include <string>            // For std::string
#include "Task.hpp"          // We pass Task objects to plugins

// Abstract base class for all plugins
class PluginInterface {
public:
    virtual ~PluginInterface() = default;  // Virtual destructor (good practice for interfaces)

    // Every plugin must have a name
    virtual std::string name() const = 0;

    // Every plugin must implement how it analyzes a task
    virtual void analyzeTask(const Task& t) = 0;
};

// C-style exported functions for dynamic loading
extern "C" {
    PluginInterface* create_plugin();         // Factory function to create a plugin instance
    void destroy_plugin(PluginInterface*);   // Function to delete plugin instance
}
