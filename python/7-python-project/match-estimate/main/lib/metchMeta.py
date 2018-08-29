from main.lib.httpmehod import HttpMethod
import json

##################
# footbool api
##################
def getOiTicket(id):
    metaAddr = "http://wx.sichuan.95504.net/d/dwr/hkezSCActivityService/checkCouponForTen"
    data = "ps=%5B'{0}'%2C'16294977538%2C16295128571%2C17291176748'%5D&ss=%7B%7D".format(id)
    resData = HttpMethod.post(metaAddr, data)
    res = json.loads(resData)

    return res


def getMatchMeta(id):
    metaAddre = "http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/getNowGameRule"

    data = "ps=%5B'{0}'%5D&ss=%7B%7D".format(id)

    resData = HttpMethod.post(metaAddre, data)

    res = json.loads(resData)

    if not 'status' in res.keys() or res['status'] != 1:
        raise IOError(res)

    return res['GameRules']


def putResult(userId, resultJson):
    metaAddre = "http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/voteSubmitSave"

    data = "ps=%5B'{0}'%2C{1}%5D&ss=%7B%7D".format(userId, HttpMethod.encode(json.dumps(resultJson)))
    resData = HttpMethod.post(metaAddre, data)

    res = json.loads(resData)

    if not 'status' in res.keys() or res['status'] != 1:
        raise IOError(res)


def getResult(userId):
    metaAddre = "http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/drawCupBottle"
    data = "ps=%5B'{0}'%2C'11095158755'%2C1%5D&ss=%7B%7D".format(userId)
    resData = HttpMethod.post(metaAddre, data)
    res = json.loads(resData)

    if 'ccName' in res.keys():
        return res['ccName']

    raise IOError(res)