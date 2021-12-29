#!/usr/bin/env python
"""
decorator tutorial

https://www.programiz.com/python-programming/decorator
Decorator with arguments!
Chained decorator
"""

def smart_dev(func):
    def inner(a, b): # arguments of this function will be same as the arguments
    # of the function that to be decorated!!!
        if b == 0:
            print('error, undefined division')
            return                  
        ret_val = func(a, b)
        return ret_val

    return inner

@smart_dev
def dev(a, b):    
    return a/b
#dev = smart_dev(dev)

print(f' {dev(10, 5)}')
print(f' {dev(10, 0)}')
