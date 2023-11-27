


#ifndef SYSTEM_MONITOR_READER_BASE_HPP
#define SYSTEM_MONITOR_READER_BASE_HPP

#include "system_monitor_interface.hpp"
#include "system_monitor_common.hpp"

/**
 * @brief The base class for system monitor readers.
 *
 * This class provides an interface for system monitor readers.
 * It inherits from the SystemMnotirInterface class.
 */
class SystemMonitorReaderBase
{
private:
    /**
     * @brief The SystemMonitorInterface object to store the system information.
     */
    ISystemMonitorSender& system_info_;
public:
    /**
     * @brief Destructor for the SystemMonitorReaderBase class.
     */
    virtual ~SystemMonitorReaderBase() {}

    /**
     * @brief Initializes the system monitor reader.
     */
    virtual void init() = 0;

    /**
     * @brief Reads system information.
     */
    virtual void readSystemInformation() = 0;

    /**
     * @brief Puts system information into the provided SystemMonitorInterface object.
     *
     * @param system_info The SystemMonitorInterface object to store the system information.
     */
    virtual void putSystemInformation(ISystemMonitorSender& system_info) = 0;

    /**
     * @brief Stops the system monitor reader.
     */
    virtual void stop() = 0;
};

#endif // SYSTEM_MONITOR_READER_BASE_HPP
