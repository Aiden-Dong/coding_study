
from main.lib.httpmehod import HttpMethod
import json
import datetime



def getMatchMeta(id):
    metaAddre="http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/getNowGameRule"

    data="ps=%5B'{0}'%5D&ss=%7B%7D".format(id)

    resData = HttpMethod.post(metaAddre, data)
    
    res = json.loads(resData)

    if not 'status' in res.keys() or res['status'] != 1 :
        raise IOError(res)

    #
    return res['GameRules']




def putResult(userId, resultJson):


    metaAddre = "http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/voteSubmitSave"

    data = "ps=%5B'{0}'%2C{1}%5D&ss=%7B%7D".format(userId, HttpMethod.encode(json.dumps(resultJson)))
    resData = HttpMethod.post(metaAddre, data)

    res = json.loads(resData)

    if not 'status' in res.keys() or res['status'] != 1 :
        raise IOError(res)

def getResult(userId):
    metaAddre = "http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/drawCupBottle"
    data = "ps=%5B'{0}'%2C'11095158755'%2C1%5D&ss=%7B%7D".format(userId)
    resData = HttpMethod.post(metaAddre, data)
    res = json.loads(resData)

    if 'ccName' in res.keys():
        return res['ccName']

    raise IOError(res)


def main():

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
    print("start: {0} ... " .format(datetime.datetime.now()))


    for userId in fp:
        try:
            userId = userId.replace("\n", "")
            putResult(userId, resultList)
            res = getResult(userId)
            fout.write("{0}:{1}\r\n".format(userId, res))
            fout.flush()
        except IOError as e:
            print("{0} {1}".format(userId, e))

    print("finish: {0}".format(datetime.datetime.now()))


if __name__ == '__main__':
    main()