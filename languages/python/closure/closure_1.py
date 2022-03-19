#!/usr/bin/env python3

def print_msg(msg):
    def printer():
        print(msg)

    return printer

new = print_msg('hello')
new()
new()
new()
new1 = print_msg('World')
new1()
new()
