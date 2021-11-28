#!/usr/bin/end python3

def fib(n):
    # fib smaller than 10
    a = 0
    b = 1
    while a < n:
        print(a, end = ' ')  
        a, b = b, a + b
    print('')

    print(f'first {n=} fib numbers:', end = ' ')
    a = 0
    b = 1    
    while n < 10:
        print(a, end = ' ')    
        a, b = b, a + b
        n += 1

fib(n=10)