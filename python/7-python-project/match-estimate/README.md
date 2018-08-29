#### 获取球队比赛信息:

接口: `http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/getNowGameRule`
方法: `POST`
data: `ps: ['owriLtzawu-1cVgzOYpfQSK_Hkq8']&ss:{}` => ps=%5B'owriLtzawu-1cVgzOYpfQSK_Hkq8'%5D&ss=%7B%7D
Content-Type : application/x-www-form-urlencoded; charset=UTF-8

return :

```
{
    "time": "6月15日",
    "joinFlag": false,
    "status": 1,
    "GameRules": [
        {
            "teamA": {
                "countryId": 100002,
                "name": "埃及",
                "imgUrl": "static/img/guoqi/aiji.png"
            },
            "teamB": {
                "countryId": 100003,
                "name": "乌拉圭",
                "imgUrl": "static/img/guoqi/wulagui.png"
            },
            "teamId": "14001326944",
            "checkId": ""
        },
        {
            "teamA": {
                "countryId": 100004,
                "name": "摩洛哥",
                "imgUrl": "static/img/guoqi/moluoge.png"
            },
            "teamB": {
                "countryId": 100005,
                "name": "伊朗",
                "imgUrl": "static/img/guoqi/yilang.png"
            },
            "teamId": "14021385271",
            "checkId": ""
        },
        {
            "teamA": {
                "countryId": 100006,
                "name": "葡萄牙",
                "imgUrl": "static/img/guoqi/putaoya.png"
            },
            "teamB": {
                "countryId": 100007,
                "name": "西班牙",
                "imgUrl": "static/img/guoqi/xibanya.png"
            },
            "teamId": "13441485002",
            "checkId": ""
        }
    ]
}

```


#### 获取用户名称信息:

接口: `http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/getUserVictory`
方法: `POST`
data: `ps: ['owriLtzawu-1cVgzOYpfQSK_Hkq8']&ss:{}` => ps=%5B'owriLtzawu-1cVgzOYpfQSK_Hkq8'%5D&ss=%7B%7D
Content-Type : application/x-www-form-urlencoded; charset=UTF-8

return :
```
{
    "name": "斯达克",
    "victory": 0,
    "victoryRate": 0
}
```


#### 提交:

接口 : `http://wx.sichuan.95504.net/d/dwr/hkezSCActivityGameService/voteSubmitSave`
方法 : `POST`
data : `ps: ['owriLtzawu-1cVgzOYpfQSK_Hkq8',[{teamId:'15050953715',voteCountryId:100000}]]&ss: {}` => `ps=%5B'owriLtzawu-1cVgzOYpfQSK_Hkq8'%2C%5B%7BteamId%3A'15050953715'%2CvoteCountryId%3A100000%7D%5D%5D&ss=%7B%7D`

result :

```
{"_error": "\u60A8\u5DF2\u53C2\u52A0\u8FC7\u4ECA\u65E5\u7ADE\u731C\uFF0C\u8BF7\u5173\u6CE8\u660E\u5929\u7684\u7ADE\u731C\uFF01"}
```


#### 转盘:

接口 : `http://wx.sichuan.95504.net/d/dwr/scanActivetyRuleMgntService/drawCupBottle`
方法 : `POST`
data : `ps: ['owriLtzawu-1cVgzOYpfQSK_Hkq8','11095158755',1]&ss: {}`

return :

```
{
    "ccName": "门票折扣券（南湖梦幻岛嬉水乐园）",
    "amount": 0,
    "limitAmount": 0,
    "oillimitAmount": 0,
    "ttlimitAmount": 0,
    "tSum": 1,
    "totalAmount": 0,
    "totalNum": 1,
    "couponList": [
        {
            "ccName": "门票折扣券（南湖梦幻岛嬉水乐园）",
            "amount": 0,
            "limitAmount": 0,
            "oillimitAmount": 0,
            "ttlimitAmount": 0,
            "tSum": 1
        }
    ],
    "idx": 2,
    "status": 1,
    "msg": "领取成功！"
}
```