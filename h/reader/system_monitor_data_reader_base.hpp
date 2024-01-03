#ifndef SYSTEM_MONITOR_DATA_READER_BASE_HPP
#define SYSTEM_MONITOR_DATA_READER_BASE_HPP

#include "sender/system_monitor_sender_interface.hpp"

/**
 * @brief The base class for system monitor readers.
 *
 * This class provides an interface for system monitor readers.
 * It inherits from the SystemMnotirInterface class.
 */
class SystemMonitorDataReaderBase {
 public:
  /**
   * @brief Constructs a SystemMonitorDataReaderBase object.
   */
  SystemMonitorDataReaderBase() = default;

  /**
   * @brief Destructor for the SystemMonitorDataReaderBase class.
   */
  virtual ~SystemMonitorDataReaderBase() = default;

  /**
   * @brief Initializes the system monitor reader.
   */
  virtual bool init() = 0;

  /**
   * @brief Reads system information.
   */
  virtual bool start() = 0;

  /**
   * @brief Stops the system monitor reader.
   */
  virtual bool stop() = 0;

  /**
   * @brief Reads system information.
   */
  virtual bool readSystemInformation(SystemMonitorData& current_data) = 0;
};

#endif  // SYSTEM_MONITOR_DATA_READER_BASE_HPP
