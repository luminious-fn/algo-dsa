#!/usr/bin/env python3

def my_decorator(func):
    def inner(name):
        name_upper = name.upper()
        func(name_upper)

    return inner

@my_decorator
def print_name(name):
    print(f"hello {name=}")

#print_name = my_decorator(print_name)

print_name('auM')

















