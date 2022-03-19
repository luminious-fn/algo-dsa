#!/usr/bin/env python3
L = [1, 2, 3, 4]
i = iter(L)
print(next(i))
print(next(i))
print(next(i))

i1 = iter(L)
print(next(i1))
try:
    print(next(i1))
except StopIteration:
    print('exception StopIteration occurred!!!')


class PowerTo:
    """ docstring """

    def __init__(self, max_power=0):
        self.max_power = max_power

    def __iter__(self):
        self.iteration = -1
        return self

    def __next__(self):
        if self.iteration >= self.max_power:
            print('StopIteration')
            raise StopIteration

        self.iteration += 1
        print(f'returning power of 2**{self.iteration}')
        return 2 ** self.iteration


x = PowerTo(3)
#i = iter(x)
i = x.__iter__()
i.__next__()
next(i)
next(i)
next(i)
try:
    next(i)
except :
#except StopIteration:
    print('got StopIteration')

print('in for loop')
for i in x:
    print(i)

def my_generator():
    for i in range(10):
        yield i

print(my_generator)
for i in my_generator():
    print(f'{i}')


