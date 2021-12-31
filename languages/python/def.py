#!/usr/bin/env python

def fun(name, /, kw1, **arg_dict):
    print(f'{name=} {kw1=}')

    for k in arg_dict.:
        print(f'{k=} {arg_dict[k]=}')

fun('prabhu', kw1 = 40, arg1 = 1 )
