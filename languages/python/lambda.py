#!/usr/bin/env python
def fun():
    incr = lambda x: x + 1
    return incr
my_incr = fun()

x = my_incr(5)
print(f'{x=}') # 6
