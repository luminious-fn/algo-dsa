#!/usr/bin/env python3

def fun(count: list =[1,2]) -> None:
    """A dummy function.

    No really.
    """
    print(count)
    count.append(33)

fun()
fun([5,6])
fun()

