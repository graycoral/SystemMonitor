


#ifndef SYSTEM_MONITOR_READER_BASE_HPP
#define SYSTEM_MONITOR_READER_BASE_HPP

#include "common/system_monitor_common.hpp"

/**
 * @brief The base class for system monitor readers.
 *
 * This class provides an interface for system monitor readers.
 * It inherits from the SystemMnotirInterface class.
 */
class SystemMonitorDataReaderBase
{
public:
    /**
     * @brief Destructor for the SystemMonitorDataReaderBase class.
     */
    virtual ~SystemMonitorDataReaderBase() {}

    /**
     * @brief Initializes the system monitor reader.
     */
    virtual void init() = 0;

    /**
     * @brief Reads system information.
     */
    virtual void readSystemInformation() = 0;

    

    /**
     * @brief Stops the system monitor reader.
     */
    virtual void stop() = 0;

protected:
    std::thread thread_;
    std::mutex mutex_;
};

#endif // SYSTEM_MONITOR_READER_BASE_HPP
