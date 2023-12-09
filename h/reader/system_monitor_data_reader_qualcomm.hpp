#ifndef SYSTEM_MONITOR_READER_HPP
#define SYSTEM_MONITOR_READER_HPP

#include "system_monitor_base.hpp"
#include "system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorReaderQualcomm class.
 *
 * This class represents a Qualcomm-specific system monitor reader.
 * It inherits from the SystemMonitorBase class and implements the ISystemMonitorSender interface.
 * It provides functionality to read system information and send data to the SystemMonitorSender class.
 */
class SystemMonitorReaderQualcomm : public SystemMonitorBase {
private:
    /**
     * @brief The SystemMonitorInterface object to store the system information.
     */
    ISystemMonitorSender system_info_;
public:
    /**
     * @brief Default constructor.
     */
    SystemMonitorReaderQualcomm();

    /**
     * @brief Destructor.
     */
    ~SystemMonitorReaderQualcomm();

    /**
     * @brief Initializes the system monitor reader.
     */
    void init() override;

    /**
     * @brief Reads system information.
     */
    void readSystemInformation() override;

    /**
     * @brief Sends system information to the SystemMonitorSender class.
     *
     * @param system_info The system information to be sent.
     */
    void putSystemInformation(ISystemMonitorSender& system_info) override;

    /**
     * @brief Stops the system monitor reader.
     */
    void stop() override;
};

#endif // SYSTEM_MONITOR_READER_HPP
