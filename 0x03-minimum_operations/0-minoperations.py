#!/usr/bin/python3
""" minimum operation """


def minOperations(n):
    """ check the minimum number of operation """
    if n < 2:
        return 0
    i = 2
    count = 0
    while i <= n:
        while n % i == 0:
            count = count + i
            n = n/i
        i = i + 1
    return(count)
