#!/usr/bin/python3
"""The N queens puzzle is the challenge
of placing N non-attacking queens on
an N×N chessboard"""


def island_perimeter(grid):
    """[print solution]
    Args:
        board ([type]): [description]
    """
    perimeter = 0
    x = len(grid)
    y = len(grid[0])
    for i in range(x):
        for j in range(y):
            if(grid[i][j] == 1):
                if(i == 0 or grid[i-1][j] == 0):
                    perimeter = perimeter + 1
                if(i == x-1 or grid[i+1][j] == 0):
                    perimeter = perimeter + 1
                if(j == 0 or grid[i][j-1] == 0):
                    perimeter = perimeter + 1
                if(j == y-1 or grid[i][j+1] == 0):
                    perimeter = perimeter + 1
    return perimeter
