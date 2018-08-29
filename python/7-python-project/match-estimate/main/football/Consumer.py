import threading
from main.lib.metchMeta import  *


class Consumer(threading.Thread):


    def __init__(self, meta, idQueue, reQueue, consumeNum, lock):
        threading.Thread.__init__(self)
        self.meta = meta
        self.idQueue = idQueue
        self.reQueue = reQueue
        self.consumeNum = consumeNum
        self.lock = lock


    def run(self):

        self.lock.acquire()
        self.consumeNum = self.consumeNum+1
        self.lock.release()

        while True:
            userId = self.idQueue.get().replace("\n", "")

            if userId == "finish":
                self.idQueue.put("finish")
                self.reQueue.put("finish")
                return
            try:
                putResult(userId, self.meta)
                res = getResult(userId)
                self.reQueue.put("{0}:{1}".format(userId, res))
            except IOError as e :
                pass
                #print(os.error, "{0} {1}".format(userId, e)) 