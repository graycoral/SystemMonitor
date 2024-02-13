#!/usr/bin/env python3

from system_monitor_receiver import *

def main():
    receiver = SystemMonitorReceiver()

    if receiver.start() == False:
        print("SystemMonitorReceiver start failed")
        return

    if receiver.join() == False:
        print("SystemMonitorReceiver join failed")
        return

if __name__ == "__main__":
    main()
