import datetime
from multiprocessing import Queue
from main.affordable.get_producer import *
from main.affordable.put_consumer import *
from main.lib.affordable_meta import *

def process():
    productNum = 2000
    meta_file = "data/user_id_message.txt"
    write_meta= "data/result_{0}-{1}.txt"

    #oliQueue = Queue()
    unoliQueue = Queue()
    #nineQueue = Queue()

    #oliWriteQueue = Queue()
    unoliWriteQueue = Queue()
    #nineWriteQueue = Queue()

    with open(meta_file, "r") as f :
        for fline in f :
            userId = fline.replace("\n", "").replace("\r", "")
            #oliQueue.put(userId)
            unoliQueue.put(userId)
            #nineQueue.put(userId)


    productList = []

    # producer
    for index in range(productNum):
        #productList.append(GetProducer(oliQueue, oliWriteQueue, pushOil))
        productList.append(GetProducer(unoliQueue, unoliWriteQueue, pushUnoil))
        #productList.append(GetProducer(nineQueue, nineWriteQueue, pushNine))


    # consumer
    #productList.append(PutComsumer(oliWriteQueue, write_meta.format("oli", datetime.datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f"))))
    #productList.append(consumerOli)
    productList.append(PutComsumer(unoliWriteQueue, write_meta.format("unoli", datetime.datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f"))))
    #productList.append(consumerUnoli)
    #productList.append(PutComsumer(nineWriteQueue, write_meta.format("nine", datetime.datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f"))))
    #productList.append(consumerNine)

    for producer in productList:
        producer.start()


    for productRes in productList:
        productRes.join()

