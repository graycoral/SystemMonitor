#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include "reader/system_monitor_data_reader_base.hpp"
#include "sender/system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorDataReaderLinux class.
 *
 * This class represents a Linux-specific system monitor reader.
 * It inherits from the SystemMonitorBase class and implements the
 * ISystemMonitorSender interface. It provides functionality to read system
 * information and send data to the SystemMonitorSender class.
 */
class SystemMonitorDataReaderLinux : public SystemMonitorDataReaderBase {
 public:
  /**
   * @brief Default constructor.
   */
  SystemMonitorDataReaderLinux();

  /**
   * @brief Destructor.
   */
  ~SystemMonitorDataReaderLinux() = default;

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
   * @brief Reads system information.
   */
  bool readSystemInformation(SystemMonitorData& current_data) override;
};

#endif  // SYSTEM_MONITOR_READER_HPP
