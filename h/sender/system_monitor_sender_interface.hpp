
#ifndef SYSTEM_MONITOR_INTERFACE_HPP
#define SYSTEM_MONITOR_INTERFACE_HPP

/**
 * @brief The interface for sending system monitor updates.
 */
class ISystemMonitorSender {
 public:
  /**
   * @brief Updates the system status.
   */
  virtual void updateSystemStatus() = 0;

  /**
   * @brief Destructor.
   */
  virtual ~ISystemMonitorSender() = default;
};

#endif  // SYSTEM_MONITOR_INTERFACE_HPP
