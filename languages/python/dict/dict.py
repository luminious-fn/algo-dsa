#!/usr/bin/env python3
d = {
    'madhu': 1,
    'megha': 2,
    'pranav': 3,
    'prabhu': 4,
}

print(d)
print(list(d))
print(d.keys())
print(d.values())
print(d.items())

d1 = dict([(1,2), (3,4), (5,6)])
print(d1)

d2 = {x: x**2 for x in range(10)}
print(d2)

for (k,v) in d2.items():
    print(f'{k}, {v}')

print('enumerate')
for (index, item) in enumerate(d2.items()):
    print(f'{index}, {item}')
