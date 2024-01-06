
#ifndef SYSTEM_MONITOR_SENDER_HPP
#define SYSTEM_MONITOR_SENDER_HPP

#include "common/system_monitor_common.hpp"
#include "sender/system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorSender class.
 *
 * This class provides an interface for system monitor senders.
 * It inherits from the ISystemMonitorSender class.
 */
class SystemMonitorSender
    : public ISystemMonitorSender,
      public std::enable_shared_from_this<SystemMonitorSender> {
 public:
  /**
   * @brief Constructs a SystemMonitorSender object.
   */
  SystemMonitorSender();
  /**
   * @brief Destroys the SystemMonitorSender object.
   */
  ~SystemMonitorSender();

 public:
  /**
   * @brief Initializes the system monitor sender.
   */
  bool init();

  /**
   * @brief Starts the system monitor sender.
   */
  bool start();

  /**
   * @brief Stops the system monitor sender.
   */
  bool stop();

  /**
   * @brief Joins if the system monitor sender is joinable.
   */
  bool join();

  /**
   * @brief Updates the system status.
   */
  void updateSystemStatus(SystemMonitorData& current_data) override;

  /**
   * @brief Sends the provided system information.
   * @param current_data The system information to be sent.
   */
  void sendData(const SystemMonitorData& current_data);

  /**
   * @brief Prints the provided system information.
   * @param current_data The system information to be printed.
   */
  void debugSystemInfo(const SystemMonitorData& current_data);

 private:
  std::thread thread_;
  std::mutex mutex_;

  SystemMonitorData current_data_;
};

#endif  // SYSTEM_MONITOR_SENDER_HPP
