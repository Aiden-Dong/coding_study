
import threading
from multiprocessing import Queue

class Producer(threading.Thread):
    def __init__(self, queue, fRead):
        threading.Thread.__init__(self)
        self.queue = queue
        self.file = fRead

    def run(self):
        for item in self.file :
            self.queue.put(item)
        self.queue.put("finish")