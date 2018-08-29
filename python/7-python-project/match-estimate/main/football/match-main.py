
from main.football.Consumer import *
from main.football.FlushConsumer import *
from main.lib.metchMeta import *
from main.football.Producer import *
import datetime


def main():
    threadNum = 300
    fp = open("data/user_id_message.txt", "r")
    fout = open("data/result_message-{0}.txt".format(datetime.datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f")), "w")
    resultList = []

    meta = getMatchMeta("owriLtzawu-1cVgzOYpfQSK_Hkq8")

    print("===============猜球===========")
    print("球赛总共 : {0} 场".format(len(meta)))

    for i in range(len(meta)):
        choose = input("第 {0} 场: {1}(A), {2}(B), pint(C) : ".format(i, meta[i]['teamA']['name'], meta[i]['teamB']['name']))
        resItem = {}
        resItem['teamId'] = str(meta[i]['teamId'])
        if choose == "A":
            resItem['voteCountryId'] = meta[i]['teamA']['countryId']
        elif choose == "B":
            resItem['voteCountryId'] = meta[i]['teamB']['countryId']
        elif choose == "C":
            resItem['voteCountryId'] = 'ping'
        else:
            print("Your input error : [{0}], you should input [A , B , C]".format(choose))
            return
        resultList.append(resItem)
    print("=====================================")
    print("start: {0} ... ".format(datetime.datetime.now()))

    idQueue = Queue()
    resQueue = Queue()
    consumeNum = 0


    producter = Producer(idQueue, fp)
    lock = threading.Lock()

    idConsumerList = []

    for index in range(threadNum) :
        idConsumerList.append(Consumer(resultList, idQueue, resQueue, consumeNum, lock))

    flushConsumer = FlushConsumer(resQueue, consumeNum, lock, fout)


    producter.start()
    for index in range(threadNum):
        idConsumerList[index].start()
    flushConsumer.start()

    producter.join()
    for index in range(threadNum):
        idConsumerList[index].join()
    flushConsumer.join()



    print("finish: {0}".format(datetime.datetime.now()))


if __name__ == '__main__':
    main()