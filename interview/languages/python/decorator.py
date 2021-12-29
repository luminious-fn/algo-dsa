#!/usr/bin/env python3
"""
basic decorator function
"""
import sys
import functools

def my_decorator2(func):
    """ decorator 2 """
    print(f'{sys._getframe().f_code.co_name}')
    @functools.wraps(func)
    def wrapper2(*args, **kwargs):
        print(f'{sys._getframe().f_code.co_name}')
        print('prefix 2')
        r = func(*args, **kwargs)
        print('suffix 2')
        return r
    return wrapper2

def my_decorator(func1):
    """ decorator 1 """
    #print(f'{sys._getframe().f_code.co_name}')
    def wrapper(func):
        #print(f'{sys._getframe().f_code.co_name}')
        print('prefix: 1')
        def inner(name):
            print(f'inner({name}) ')
            func(name)
        print('suffix: 1')
        return inner
    return wrapper

#@my_decorator2('eeeeee')
#@my_decorator
def func(name):
    """ to be decorated """
    pass
    print(f'{sys._getframe().f_code.co_name}')
    #print(f'name')
    return 'hi'

func = (my_decorator('arg'))(func)
#print('calling func')
s = func('aum')
#print(s)
#fun('aum')

