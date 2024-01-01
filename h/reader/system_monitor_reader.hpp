
#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include "common/system_monitor_common.hpp"
#include "reader/system_monitor_data_reader_base.hpp"
#include "sender/system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorReader class is responsible for reading system
 * monitor data.
 */
class SystemMonitorReader
    : public std::enable_shared_from_this<SystemMonitorReader> {
 public:
  /**
   * @brief Constructs a SystemMonitorReader object.
   */
  SystemMonitorReader(std::weak_ptr<ISystemMonitorSender>& system_iterface);

  /**
   * @brief Destroys the SystemMonitorReader object.
   */
  virtual ~SystemMonitorReader() = default;

  /**
   * @brief Initializes the system monitor reader.
   */
  bool init();

  /**
   * @brief Stops the system monitor reader.
   */
  bool stop();

  /**
   * @brief Reads the system monitor data.
   */
  bool readData();

  /**
   * @brief Starts the system monitor reader.
   */
  bool start();

  /**
   * @brief Joins if the system monitor reader is joinable.
   * @return true if joining is successful, false otherwise.
   */
  bool join();

 private:
  /**
   * @brief Puts system information into the provided SystemMonitorInterface
   * object.
   */
  void putSystemInformation();

 private:
  /**
   * @brief The base class for the SystemMonitorDataReader.
   *
   * This class provides the interface for reading system monitor data.
   */
  std::shared_ptr<SystemMonitorDataReaderBase> data_reader_;

  /**
   * @brief The SystemMonitorInterface object to store the system information.
   */
  std::weak_ptr<ISystemMonitorSender> system_interface_;

  SystemMonitorData prev_data_;

  std::thread thread_;
  std::mutex mutex_;
};

#endif  // SYSTEM_MONITOR_READER_HPP
