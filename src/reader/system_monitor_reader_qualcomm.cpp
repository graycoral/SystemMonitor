
#include "system_monitor_reader_base.h"
#include "system_monitor_interface.h"
#include "sender.h"

class SystemMonitorReaderQualcomm : public SystemMonitorReaderBase, public SystemMonitorInterface {
public:
    void updateData() override {
        // Implementation to update data
        // ...
        // Call sender class to send data
        Sender::getInstance().sendData();
    }
};
