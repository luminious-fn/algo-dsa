#!/usr/bin/env python
import sys

hello = 555
print(f'{sys.platform=}')
assert ('linux' in sys.platform), hello

try:
    print('I am int try')
    #my_place = city
    a = 0/0
except ZeroDivisionError as zerr:
    print(f'zero div error {zerr}')
except Exception as my_exept:
    print(f'except: an exception occured: {my_exept=}    {type(my_exept)}')
else:
    print('else: no exception occured. This runs after clean Try always')
finally:
    print('finally: runs always no matter what: this too runs at the end of Try')

