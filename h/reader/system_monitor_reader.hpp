
#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include <vector>

#include "system_monitor_base.hpp"

/**
 * @brief The SystemMonitorReader class is responsible for reading system monitor data.
 */
class SystemMonitorReader {
private:
    /**
     * @brief The base class for the SystemMonitorDataReader.
     *
     * This class provides the interface for reading system monitor data.
     */
    SystemMonitorDataReaderBase data_reader_;

    /**
     * @brief The SystemMonitorInterface object to store the system information.
     */
    ISystemMonitorSender& system_info_;

public:
    /**
     * @brief Constructs a SystemMonitorReader object.
     */
    SystemMonitorReader();

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
private:
    /**
     * @brief Puts system information into the provided SystemMonitorInterface object.
     *
     * @param system_info The SystemMonitorInterface object to store the system information.
     */
    void putSystemInformation(ISystemMonitorSender& system_info);

    /**
     * @brief Structure to hold system monitor data.
     */
    struct SystemMonitorData {
        std::vector<float> cpu_usage;
        std::vector<float> cpu_temperature;
        std::vector<float> gpu_usage;
    };

    SystemMonitorData prev_data_;
};

#endif // SYSTEM_MONITOR_READER_HPP
