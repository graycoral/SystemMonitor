
#include <iostream>

#include "system_monitor.hpp"

std::unique_ptr<SystemMonitor> system_monitor;

int main(int argc, char* argv[]) {
    system_monitor = std::make_unique<SystemMonitor>();

    if(!system_monitor->init()) {
        return 1;
    };

    if(!system_monitor->start()) {
        return 1;
    }

    if(!system_monitor->stop()) {
        return 1;
    }

    return 0;
}
