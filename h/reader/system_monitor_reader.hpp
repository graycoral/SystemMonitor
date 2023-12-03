
#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include "system_monitor_base.hpp"
#include "system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorReader class is responsible for reading system monitor data.
 */
class SystemMonitorReader {
private:
    SystemMonitorDataReaderBase data_reader_;
    ISystemMonitorSender& system_info_;

public:
    /**
     * @brief Constructs a SystemMonitorReader object.
     */
    SystemMonitorReader();

    /**
     * @brief Destroys the SystemMonitorReader object.
     */
    virtual ~SystemMonitorReader();

    /**
     * @brief Initializes the system monitor reader.
     */
    virtual void init() = 0;

    /**
     * @brief Stops the system monitor reader.
     */
    virtual void stop() = 0;

    /**
     * @brief Reads the system monitor data.
     */
    virtual void readData()  = 0;
};

#endif // SYSTEM_MONITOR_READER_HPP
