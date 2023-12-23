#include "reader/system_monitor_data_reader_linux.hpp"

#include <memory.h>

#include <fstream>

const char* filename = "/proc/stat";

SystemMonitorDataReaderLinux::SystemMonitorDataReaderLinux() { prev_data_{}; }

SystemMonitorDataReaderLinux::~SystemMonitorDataReaderLinux() {
  cur_data_.reset();
}

bool SystemMonitorDataReaderLinux::init() {
  // Initialize the data reader

  return true;
}

bool SystemMonitorDataReaderLinux::start() {
  // Start the data reader

  return true;
}

bool SystemMonitorDataReaderLinux::stop() {
  // Stop the data reader

  return true;
}

bool SystemMonitorDataReaderLinux::join() {
  // Join the data reader thread
  if (thread_.joinable()) {
    thread_.join();
  } else {
    return false;
  }

  return true;
}

void SystemMonitorDataReaderLinux::readSystemInformation() {
  std::ifstream file(filename);
  std::string line;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      // Parse the line and update cur_data_
      // This is a placeholder, replace it with actual parsing logic
      if (line.find("cpu") != std::string::npos) {
        // Parse CPU data
        std::istringstream iss(line);
        std::vector<std::string> tokens(std::istream_iterator<std::string>{iss},
                                        std::istream_iterator<std::string>());

        if (tokens.size() >= 5) {
          // Extract CPU usage values from tokens
          long user = std::stol(tokens[1]);
          long nice = std::stol(tokens[2]);
          long system = std::stol(tokens[3]);
          long idle = std::stol(tokens[4]);

          // Calculate CPU usage percentage
          long total = user + nice + system + idle;
          double usage = (total - idle) / static_cast<double>(total) * 100.0;

          // Update cur_data_ with CPU usage
          cur_data_.cpuUsage = usage;
        }
      } else if (line.find("meminfo") != std::string::npos) {
        // Parse memory data
      }
      // Add more conditions to parse other types of data
    }
    file.close();
  } else {
    std::cerr << "Unable to open /proc/stat" << std::endl;
  }
}