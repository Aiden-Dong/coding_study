import threading
from main.lib.affordable_meta import *

class GetProducer(threading.Thread):
    def __init__(self, readQueue, writeQueue, func):
        threading.Thread.__init__(self)
        self.readQueue = readQueue
        self.writeQueue = writeQueue
        self.func = func

    def run(self) :

        while True:
            userId = self.readQueue.get().replace("\n", "")

            if userId == "finish":
                self.readQueue.put(userId)
                break

            try:
                self.func(userId)
                self.writeQueue.put(userId)
            except IOError as e:
                pass
            self.readQueue.put(userId)
