#!/usr/bin/env python3
# https://www.pythonpool.com/match-case-python/
x1 = 3
match x1:
    case 1:
        print('it is one')
    case 2 | 3 :
        print('it is 2 or 3')
    case _:
        print('it is default')