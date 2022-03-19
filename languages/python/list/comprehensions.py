#!/usr/bin/env python3

m = [
    [1,2,3,4],
    [5,6,7,8],
]
tm = []
for i in range(4):
    tm.append([])
    for row in m:
        tm[i].append(row[i])

print(tm)

tm1 = [ [row[i] for row in m] for i in range(4)]
print(tm1)