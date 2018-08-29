from datetime import datetime


# check
def testTime():
    dayNow = datetime.strftime(datetime.now(), '%Y-%m-%d')
    checkTime = datetime.strptime('{0} 10:00:00'.format(dayNow), '%Y-%m-%d %H:%M:%S')


