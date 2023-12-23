#ifndef SYSTEM_MONITOR_DATA_READER_BASE_HPP
#define SYSTEM_MONITOR_DATA_READER_BASE_HPP

#include "common/system_monitor_common.hpp"
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
  SystemMonitorDataReaderBase(ISystemMonitorSender sender_interface);

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
   * @brief Joins if the system monitor reader is joinable.
   */
  virtual bool join() = 0;

  virtual bool readSystemInformation() = 0;

 private:
  ISystemMonitorSender system_info_;

 protected:
  std::thread thread_;
  std::mutex mutex_;
};

#endif  // SYSTEM_MONITOR_DATA_READER_BASE_HPP
