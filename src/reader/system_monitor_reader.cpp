#include "reader/system_monitor_reader.hpp"

SystemMonitorReader::SystemMonitorReader() : data_reader_(nullptr), system_info_(nullptr)
{
    data_reader_ = std::make_unique<SystemMonitorDataLinux>();
    system_info_ = std::make_unique<ISystemMonitorSender>();
}

SystemMonitorReader::~SystemMonitorReader()
{
    data_reader_.reset();
    system_info_.reset();
}

bool SystemMonitorReader::init()
{
    if(data_reader_ != nullptr)
    {
        data_reader_->init();
    } else {
        return false;
    }

    if(system_info_ != nullptr)
    {
        system_info_->init();
    } else {
        return false;
    }

    return true;
}

bool SystemMonitorReader::start()
{
    if(data_reader_ != nullptr)
    {
        data_reader_->start();
    } else {
        return false;
    }

    if(system_info_ != nullptr)
    {
        system_info_->start();
    } else {
        return false;
    }

    return true;
}

bool SystemMonitorReader::stop()
{
    if(data_reader_ != nullptr)
    {
        data_reader_->stop();
    } else {
        return false;
    }

    if(system_info_ != nullptr)
    {
        system_info_->stop();
    } else {
        return false;
    }

    return true;
}
