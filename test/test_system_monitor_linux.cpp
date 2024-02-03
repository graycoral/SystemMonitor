#include <gtest/gtest.h>

#include "reader/system_monitor_data_reader_linux.hpp"

TEST(SystemMonitorDataReaderLinux, init) {
  SystemMonitorDataReaderLinux system_monitor_data_reader_linux;
  EXPECT_TRUE(system_monitor_data_reader_linux.init());
}  // SystemMonitorDataReaderLinux, init