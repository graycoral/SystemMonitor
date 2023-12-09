
#include "system_monitor.hpp"

SystemMonitor::SystemMonitor() : reader_(nullptr), sender_(nullptr)
{
    reader_ = std::make_unique<SystemMonitorDataReader>();
    sender_ = std::make_unique<SystemMonitorSender>();
}

bool SystemMonitor::init()
{
    if(reader_ != nullptr)
    {
        reader_->init();
    } else {
        return false;
    }

    if(sender_ != nullptr)
    {
        sender_->init();
    } else {
        return false;
    }

    return true;
}

bool SystemMonitor::start()
{
    if(reader_ != nullptr)
    {
        reader_->start();
    } else {
        return false;
    }

    if(sender_ != nullptr)
    {
        sender_->start();
    } else {
        return false;
    }

    return true;
}

bool SystemMonitor::stop()
{
    if(reader_ != nullptr)
    {
        reader_->stop();
    } else {
        return false;
    }

    if(sender_ != nullptr)
    {
        sender_->stop();
    } else {
        return false;
    }

    return true;
}