#include "PluginInterface.hpp"  // Needed to inherit PluginInterface
#include <iostream>             // For std::cout

// A sample plugin that looks for processes with "bash" in their name
class SamplePlugin : public PluginInterface {
public:
    // Return plugin name
    std::string name() const override {
        return "Sample Plugin";
    }

    // Analyze a single task
    void analyzeTask(const Task& t) override {
        // If process name contains "bash"
        if (t.getName().find("bash") != std::string::npos) {
            // Print its PID
            std::cout << "[Plugin] Found bash process: PID " << t.getPid() << "\n";
        }
    }
};

// These functions are exported for dynamic loading
extern "C" PluginInterface* create_plugin() {
    return new SamplePlugin();   // Return new plugin instance
}

extern "C" void destroy_plugin(PluginInterface* p) {
    delete p;                    // Clean up
}
