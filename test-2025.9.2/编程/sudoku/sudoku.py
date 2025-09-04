import random 
import sys
import math

sys.setrecursionlimit(100000)

def get_next(m, x, y):
    n = len(m)
    for next_y in range(y+1, n): 
        if m[x][next_y] == 0:
            return x, next_y
    for next_x in range(x+1, n): 
        for next_y in range(0, n):
            if m[next_x][next_y] == 0:
                return next_x, next_y
    return -1, -1

def value(m, x, y):
    n = len(m)
    block_size = int(math.sqrt(n))
    i, j = x // block_size, y // block_size
    grid = [m[i*block_size + r][j*block_size + c] 
            for r in range(block_size) for c in range(block_size)]
    v = set(range(1, n+1)) - set(grid) - set(m[x]) - set(list(zip(*m))[y])
    return list(v)

def start_pos(m):
    n = len(m)
    for x in range(n):
        for y in range(n):
            if m[x][y] == 0:
                return x, y
    return False, False

def try_sudoku(m, x, y):
    for v in value(m, x, y):
        m[x][y] = v
        next_x, next_y = get_next(m, x, y)
        if next_y == -1:  # 如果无下一个空白格
            return True
        else:
            end = try_sudoku(m, next_x, next_y)  # 递归
            if end:
                return True
            m[x][y] = 0  # 回溯
    return False

def sudoku(m):
    x, y = start_pos(m)
    if x is False:
        print("数独已解决")
        return
    try_sudoku(m, x, y)
    for row in m:
        print(row)
    print()

if __name__ == "__main__":
    #例

    # 9x9 数独
    m9 = [
        [6, 0, 0, 1, 0, 0, 7, 0, 8],
        [0, 0, 0, 8, 0, 0, 2, 0, 0],
        [2, 3, 8, 0, 5, 0, 1, 0, 0],
        [0, 0, 0, 0, 4, 0, 0, 9, 2],
        [0, 0, 4, 3, 0, 8, 6, 0, 0],
        [3, 7, 0, 0, 1, 0, 0, 0, 0],
        [0, 0, 3, 0, 7, 0, 5, 2, 6],
        [0, 0, 2, 0, 0, 4, 0, 0, 0],
        [9, 0, 7, 0, 0, 6, 0, 0, 4]
    ]

    # 4x4 数独

    m4 = [
        [0, 3, 1, 0],
        [2, 0, 0, 0],
        [0, 0, 4, 1],
        [0, 0, 0, 3]
    ]
    
    print("9x9:")
    sudoku(m9)
    
    print("4x4:")
    sudoku(m4)