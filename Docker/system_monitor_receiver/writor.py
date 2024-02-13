import threading
import time

class Writor(threading.Thread):
    def __init__(self, write_sleep_time):
        print("Writor.__init__()")
        self.sleep_time = write_sleep_time
    def start(self):
        print("Writor.start()")
        while True:
            print("TESt")
            time.sleep(self.sleep_time)

        return True
    def stop(self):
        print("Writor.stop()")
        return True
    def join(self):
        self.join()


