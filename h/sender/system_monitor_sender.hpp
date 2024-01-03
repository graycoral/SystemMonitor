
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
class SystemMonitorSender : public ISystemMonitorSender {
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
   * @brief Sends the provided data.
   * @param data The data to be sent.
   */
  void sendData(const std::string& data);
};

#endif  // SYSTEM_MONITOR_SENDER_HPP
