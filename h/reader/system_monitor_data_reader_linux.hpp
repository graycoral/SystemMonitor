#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include "system_monitor_base.hpp"
#include "system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorReaderLinux class.
 *
 * This class represents a Linux-specific system monitor reader.
 * It inherits from the SystemMonitorBase class and implements the
 * ISystemMonitorSender interface. It provides functionality to read system
 * information and send data to the SystemMonitorSender class.
 */
class SystemMonitorReaderLinux : public SystemMonitorDataReaderBase {
 public:
  /**
   * @brief Default constructor.
   */
  SystemMonitorReaderLinux();

  /**
   * @brief Destructor.
   */
  ~SystemMonitorReaderLinux() = default;

  /**
   * @brief Initializes the system monitor reader.
   */
  bool init() override;

  /**
   * @brief Starts the system monitor reader.
   */
  bool start() override;

  /**
   * @brief Stops the system monitor reader.
   */
  bool stop() override;

  /**
   * @brief Starts the system monitor reader.
   */
  bool join() override;

  /**
   * @brief Reads system information.
   */
  void readSystemInformation() override;
};

#endif  // SYSTEM_MONITOR_READER_HPP
