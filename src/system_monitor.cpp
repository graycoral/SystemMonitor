
#include "system_monitor.hpp"

SystemMonitor::SystemMonitor() : reader_(nullptr), sender_(nullptr)
{
    reader_ = std::make_unique<SystemMonitorDataReaderBase>();
    sender_ = std::make_unique<SystemMonitorSender>();
}

bool SystemMonitor::init()
{
    if(reader_ != nullptr)
    {
        reader_->init();
    }

    if(sender_ != nullptr)
    {
        sender_->init();
    }
}