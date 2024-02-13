from writor import *
from communicator import *

class  SystemMonitorReceiver():
    def __init__(self):
        print("SystemMonitorReceiver.__init__()")
        self.writor = Writor(1)
        self.com = Communicator()

    def start(self):
        if self.writor.start() == False:
            return False

        if self.com.start() == False:
            return False
        return True