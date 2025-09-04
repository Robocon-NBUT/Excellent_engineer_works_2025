n = int(input())  # 数独大小（4或9）
board = []        # 存储数独

# 读取数独（0表示空格）
for i in range(n):
    row = list(map(int, input().split()))
    board.append(row)

# 检查数字num放在(row, col)位置是否合法
def check(row, col, num):
    # 检查行和列
    for i in range(n):
        if board[row][i] == num or board[i][col] == num:
            return False
    
    # 检查所在小宫格
    size = 2 if n == 4 else 3  # 4阶宫格大小为2，9阶为3
    start_row = (row // size) * size
    start_col = (col // size) * size
    
    for i in range(start_row, start_row + size):
        for j in range(start_col, start_col + size):
            if board[i][j] == num:
                return False
    return True

# 递归求解数独
def solve():
    for i in range(n):
        for j in range(n):
            if board[i][j] == 0:  # 找到空格
                for num in range(1, n + 1):  # 尝试填入1到n
                    if check(i, j, num):
                        board[i][j] = num
                        if solve():  # 递归求解
                            return True
                        board[i][j] = 0  # 回溯
                return False  # 无可用数字，返回失败
    return True  # 填满所有空格，求解成功

# 求解数独
solve()

# 输出结果
for i in range(n):
    for j in range(n):
        print(board[i][j], end="")
        if j != n - 1:
            print(" ", end="")
    print()
