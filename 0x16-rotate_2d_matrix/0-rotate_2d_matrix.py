#!/usr/bin/python3
"""
0x16 - Rotate 2D Matrix
"""


def rotate_2d_matrix(matrix):
    """ Rotate 90° matrix Rotate 2D Matrix
    n² time complexity
    """
    temp = matrix.copy()
    matrix.clear()
    for y in range(len(temp[0])):
        t = []
        for x in reversed(range(len(temp))):
            t.append(temp[x][y])
        matrix.append(t)
