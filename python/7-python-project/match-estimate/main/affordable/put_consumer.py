import threading


class PutComsumer(threading.Thread):

    def __init__(self, writeQueue, filename):
        threading.Thread.__init__(self)
        self.writeQueue = writeQueue
        self.filename = open(filename, "w")

    def run(self) :
        while True:
            userId = self.writeQueue.get()
            self.filename.write("{0}\r\n".format(userId))
            self.filename.flush()

