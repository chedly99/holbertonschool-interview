#!/usr/bin/python3
"""The N queens puzzle"""
import sys


def printBoard(board):
    """[print solution]
    Args:
        board ([type]): [description]
    """
    rowx = []
    for x in board:
        for c in x:
            if c == 1:
                rowx.append([board.index(x), x.index(c)])
    print(rowx)


def isSafe(board, row, col, N):
    """
    Check if the current position is safe
    """
    for i in range(col):

        if board[row][i] + board[row][i + 1] != 0:
            return False

    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    for i, j in zip(range(row, N, 1), range(col, -1, -1)):
        if board[i][j] == 1:
            return False

    return True


def nQueen(board, col, N):
    """[Place the Queen in the right position]
    """

    if (col >= N):
        printBoard(board)

    for x in range(N):
        if isSafe(board, x, col, N):
            board[x][col] = 1
            if nQueen(board, col+1, N):
                return True
            board[x][col] = 0

    return False


# initial run starting from the col 0!
def main():
    """
    Main control function
    """
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)
    if sys.argv[1].isnumeric():
        N = int(sys.argv[1])
    else:
        print("N must be a number")
        exit(1)
    if N < 4:
        print("N must be at least 4")
        exit(1)
    board = [[0 for x in range(N)] for y in range(N)]
    nQueen(board, 0, N)


if __name__ == '__main__':
    main()
