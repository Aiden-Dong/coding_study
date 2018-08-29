import threading

class FlushConsumer(threading.Thread):

    def __init__(self, resQueue, consumeNum ,lock, fout):
        threading.Thread.__init__(self)
        self.resQueue = resQueue
        self.consumeNum = consumeNum
        self.lock = lock
        self.fout = fout

    def run(self):

        while True:
            resData = self.resQueue.get()

            if resData == "finish":
                self.lock.acquire()
                self.consumeNum = self.consumeNum - 1
                self.lock.release()

                if self.consumeNum <= 0 :
                    self.fout.close()
                    return
                else:
                    continue

            self.fout.write("{0}\r\n".format(resData))
            self.fout.flush()