#!/usr/bin/python3
"""
Main file for testing
"""


def makeChange(coins, total):
    """[summary]

    Args:
        coins ([type]): [description]
        total ([type]): [description]

    Returns:
        [type]: [description]
    """
    coinsCombination = 0
    if total <= 0:
        return 0
    coins.sort()
    coins.reverse()
    for c in coins:
        coinsCombination += total // c
        total = total % c
    if (total != 0):
        return -1
    return coinsCombination
