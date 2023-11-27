
#ifndef SYSTEM_MONITOR_SENDER_HPP
#define SYSTEM_MONITOR_SENDER_HPP

class SystemMonitorSender : public ISystemMonitorSender
{
public:
    SystemMonitorSender();
    ~SystemMonitorSender();

    void sendData(const std::string& data);
};

#endif // SYSTEM_MONITOR_SENDER_HPP
