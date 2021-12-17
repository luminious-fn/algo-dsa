#!/usr/bin/env python

try:
    print('try');
    my_place = city
except Exception as my_exept:    
    print(f'except: an exception occured:= {my_exept}/{my_exept.__class__}')
else:
    print('else: no exception occured. This runs after clean Try always')
finally:
    print('finally: runs always no matter what: this too runs at the end of Try')
