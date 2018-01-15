#!/usr/bin/env python

import sys
import re

def replaceGroup(match):
    return 'home'

def main(argc, argv):
    
    f = open('data', 'r')
    reStr = r'(\w.*?):(\w{1}):(\d.*?):(\d.*?):(.*?):(.*?):(.*)'

    for strLen in f :

        # strLen=strLen[:-1];    # remove '\n'
        strLen = strLen.strip()
        print(strLen)
        userObj=re.match(reStr, strLen, flags=0)

        if userObj :
            strVal = userObj.group(7)
            #print(strVal)
            strRes = re.sub(r'\w{1,}', replaceGroup,strVal)
            print(strRes)



if __name__ == '__main__':
    main(len(sys.argv) , sys.argv[1:])
