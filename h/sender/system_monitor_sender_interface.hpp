
#ifndef SYSTEM_MONITOR_INTERFACE_HPP
#define SYSTEM_MONITOR_INTERFACE_HPP

#include "common/system_monitor_common.hpp"

/**
 * @brief The interface for sending system monitor updates.
 */
class ISystemMonitorSender {
 public:
  /**
   * @brief Updates the system status.
   */
  virtual void updateSystemStatus(SystemMonitorData& current_data) = 0;

  /**
   * @brief Destructor.
   */
  virtual ~ISystemMonitorSender() = default;
};

#endif  // SYSTEM_MONITOR_INTERFACE_HPP
