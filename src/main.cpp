
#include <iostream>
#include <memory>

#include "system_monitor.hpp"

#ifdef UNIT_TEST
#include "gtest/gtest.h"

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#else
int main(int argc, char* argv[]) {
  std::shared_ptr<SystemMonitor> system_monitor;
  system_monitor = std::make_shared<SystemMonitor>();

  if (!system_monitor->init()) {
    std::cerr << "Failed to initialize system monitor." << std::endl;
    return 1;
  };

  if (!system_monitor->start()) {
    std::cerr << "Failed to start system monitor." << std::endl;
    return 1;
  }

  if (!system_monitor->join()) {
    std::cerr << "Failed to join system monitor." << std::endl;
    return 1;
  }

  return 0;
}

#endif