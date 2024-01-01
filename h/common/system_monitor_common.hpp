#ifndef SYSTEM_MONITOR_COMMON_HPP
#define SYSTEM_MONITOR_COMMON_HPP

#include <chrono>
#include <fstream>
#include <iostream>
#include <memory>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

#include "system_monitor_log.hpp"

constexpr int kDefaultSleepTime = 1000;  // mileseconds

/**
 * @brief Structure to hold system monitor data.
 */
struct SystemMonitorData {
  std::vector<float> cpu_usage;
  std::vector<float> cpu_temperature;
  std::vector<float> gpu_usage;
};

#endif  // SYSTEM_MONITOR_COMMON_HPP
