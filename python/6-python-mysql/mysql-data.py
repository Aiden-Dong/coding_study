#!/usr/bin/env python

import MySQLdb
import gzip
from StringIO import StringIO
import json

def main():
    mysqlHostName='127.0.0.1'
    mysqlDataBase='azkaban'
    mysqlUserName='saligia'
    mysqlPassword='360628836989'

    # connect mysql
    db=MySQLdb.connect(host=mysqlHostName, user=mysqlUserName, passwd=mysqlPassword, port=3306,db=mysqlDataBase, charset='utf8')

    cursor=db.cursor()
    try:
        cursor.execute('SELECT flow_data FROM execution_flows WHERE exec_id=4578')

        data=cursor.fetchone()

        #print(data[0])
        buff=StringIO(data[0])

        fin=gzip.GzipFile(fileobj=buff, mode='rb')

        outdata = fin.read()

        jsonObj = json.loads(s=outdata, encoding='utf8')

        res = json.dumps(jsonObj)

        print(cursor.rowcount)

        print(res)

    except :
        db.rollback()
    finally:
        db.close()



if __name__ == '__main__' :
    main()
