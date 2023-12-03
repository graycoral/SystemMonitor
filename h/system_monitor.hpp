#ifndef SYSTEM_MONITOR_HPP
#define SYSTEM_MONITOR_HPP

#include "system_monitor_common.hpp"

/**
 * @brief The SystemMonitor class represents a system monitor.
 *
 * This class provides functionality to initialize, start, and stop the system monitor.
 * It also provides a method to check if the system monitor is running.
 */
class SystemMonitor
{
public:
    /**
     * @brief Constructs a SystemMonitor object.
     */
    SystemMonitor();

    /**
     * @brief Destroys the SystemMonitor object.
     */
    virtual ~SystemMonitor() = default;

    /**
     * @brief Initializes the system monitor.
     * @return true if initialization is successful, false otherwise.
     */
    bool init();

    /**
     * @brief Starts the system monitor.
     * @return true if starting is successful, false otherwise.
     */
    bool start();

    /**
     * @brief Stops the system monitor.
     * @return true if stopping is successful, false otherwise.
     */
    bool stop();

private:
    /**
     * @brief Checks if the system monitor is running.
     * @return true if the system monitor is running, false otherwise.
     */
    bool isRunning();

private:
    std::unique_ptr<SystemMonitorDataReaderBase> reader_;
    std::unique_ptr<SystemMonitorSender> sender_;

    bool is_running_;
    std::thread thread_;
    std::mutex mutex_;
};

#endif // SYSTEM_MONITOR_HPP



