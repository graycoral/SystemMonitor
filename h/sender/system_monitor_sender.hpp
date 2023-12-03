
#ifndef SYSTEM_MONITOR_SENDER_HPP
#define SYSTEM_MONITOR_SENDER_HPP

#include "common/system_monitor_common.hpp"
#include "system_monitor_sender_interface.hpp"

/**
 * @brief The SystemMonitorSender class.
 *
 * This class provides an interface for system monitor senders.
 * It inherits from the ISystemMonitorSender class.
 */
class SystemMonitorSender
    : public ISystemMonitorSender
{
public:
    /**
     * @brief Constructs a SystemMonitorSender object.
     */
    SystemMonitorSender();
    /**
     * @brief Destroys the SystemMonitorSender object.
     */
    ~SystemMonitorSender();

public:
    /**
     * @brief Updates the system status.
     */
    void updateSystemStatus() override;

    /**
     * @brief Sends the provided data.
     * @param data The data to be sent.
     */
    void sendData(const std::string& data);
};

#endif // SYSTEM_MONITOR_SENDER_HPP
