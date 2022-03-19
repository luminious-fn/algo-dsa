#!/usr/bin/env python
import fib
'''list comprehension always starts from
   left to right.
'''
# print cartisian co-cordinates 
l = [ (x, y) for x in [0, 1, 2, 3, 4] if x != 0 for y in [0, 1, 2, 3] if x != y ]
print(f' {l=}')

# flatten a 2D list
vec = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
vec_flat = [num for elem in vec for num in elem]
print(vec_flat)

# transpose a matrix
matrix = [
    [1, 2, 3, 4],
    [5, 6, 7, 8],
    [9, 10, 11, 12],
]

# transpose the matrix using list comprehensions
x = [ [elem[i] for elem in matrix] for i in range(4)]
print(x)

# transpose the matrix using normal for loop
t_matrix = []
for col in range(len(matrix[0])):
    t_row = []
    for row in matrix:
        t_row.append(row[col])
    t_matrix.append(t_row)

print(t_matrix)

a = ['a1', 'a2', 'a3']
b = ['b1', 'b2', 'b3']
c = ['c1', 'c2', 'c3']
for x, y, z in zip(a, b, c):
    print(f'{x} {y} {z}')
