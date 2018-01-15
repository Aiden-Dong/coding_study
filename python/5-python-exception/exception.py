#!/usr/bin/env python
import sys

class IllegnalError(BaseException):
    def __init__(self, args):
        self.args = args

def main():
    v_value = sys.stdin.read();

    try:
        print(v_value)
        v_num = int(v_value)
    except ValueError,e:
        raise IllegnalError(e)
    finally:
        print "stop"

if __name__ == '__main__':
    main()
