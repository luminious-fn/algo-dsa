#!/usr/bin/env python3

class Example:
    def __init__(self):
        print(' __init__ is called')

    def __del__(self):
        print('__del__ is called')

if __name__ == '__main__':
    e = Example()
    del e
    print('ended!')

