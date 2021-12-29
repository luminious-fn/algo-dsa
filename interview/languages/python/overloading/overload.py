#!/usr/bin/env python

from multipledispatch import dispatch
from typing import overload

@dispatch(int, int )
def add(n1, n2):
    print('this is for ints')
    return n1+n2

@dispatch(float, float)
def add(n1, n2):
    print('this is for floats')
    return n1+n2

add(1, 3)
add(1.1, 3.3)

@overload
def mul(n1: int, n2:int) -> int:
    print('this is for ints')
    return n1+n2

#@dispatch(float, float)
def mul(n1:float, n2:float) -> float:
    print('this is for floats')
    return n1+n2

mul(1, 3)
mul(1.1, 3.3)

