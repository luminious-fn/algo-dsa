#!/usr/bin/env python3
for i in range(2, 100):
    for j in range(2, i):
        if (i % j) == 0:
            print(f'{i=} is a prime number because, {j} is a factor or divisor')
            break
    else:
        print(f'{i=} is not a prime number')
