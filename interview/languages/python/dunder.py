#!/usr/bin/env python
""" dunder or double underscore or magic functions
in python.

https://www.geeksforgeeks.org/dunder-magic-methods-python/


"""

class A(object):
    def __init__(self, name):
        self.name = name
        return None

    def __add__(self, other) -> str:
        return self.name + other

a = A('aum')
print(f'{a = }, {a.name = }')

b = a + "DDD"
print(f'{b = }')
