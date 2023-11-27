
#include <iostream>

#include "system_monitor.hpp"

static std::unique_ptr<SystemMonitor> system_monitor;

int main(int argc, char* argv[]) {
    system_monitor = std::make_unique<SystemMonitor>();

    if(system_monitor->isRunning()) {
        std::cout << "System Monitor is running" << std::endl;
        system_monitor->start();
    } else {
        std::cout << "System Monitor is not running" << std::endl;
    }

    system_monitor->stop();
    return 0;
}
