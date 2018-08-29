from json import JSONDecodeError

from main.lib.httpmehod import HttpMethod
import json


# oil : 16294977538
def pushOil(id):
    metaAttr = "http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/checkActiveMoreBrfore"
    data = "ps=%5B'{0}'%2C16294977538%2C1%5D&ss=%7B%7D".format(id)
    resData = HttpMethod.post(metaAttr, data)

    res = {}
    try:
        res = json.loads(resData)
        if res["status"] != 1:
            raise IOError(res)
    except JSONDecodeError as e :
        print(data)
        print(resData)
    except KeyError as err :
        print(data)
        print("KeyERROR")



    #return "OK"


# unoil : 16295128571
def pushUnoil(id):
    metaAttr = "http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/checkActiveMoreBrfore"
    data = "ps=%5B'{0}'%2C16295128571%2C1%5D&ss=%7B%7D".format(id)
    resData = HttpMethod.post(metaAttr, data)

    res = {}
    try:
        res = json.loads(resData)
        if res["status"] != 1:
            raise IOError(res)

    except JSONDecodeError as e:
        print(data)
        print(resData)
    except KeyError as err :
        print(data)
        print("KeyERROR")


    #return "OK"

# nine : 17291176748
def pushNine(id):
    metaAttr = "http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/checkActiveMoreBrfore"
    data = "ps=%5B'{0}'%2C17291176748%2C1%5D&ss=%7B%7D".format(id)
    resData = HttpMethod.post(metaAttr, data)

    res = {}
    try:
        res = json.loads(resData)
        if res["status"] != 1:
            raise IOError(res)
    except JSONDecodeError as e:
        print(data)
        print(resData)
    except KeyError as err :
        print(data)
        print("KeyERROR")


    # return "OK"