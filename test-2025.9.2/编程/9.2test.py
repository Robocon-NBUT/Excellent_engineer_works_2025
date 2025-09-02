# 排序
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

def sorting_problem():
    n = int(input().strip())
    arr = list(map(int, input().split()))
    sorted_arr = quick_sort(arr)
    print(' '.join(map(str, sorted_arr)))

# 数独
def is_valid(board, row, col, num, size):
    # 检查行
    for i in range(size):
        if board[row][i] == num:
            return False
    
    # 检查列
    for i in range(size):
        if board[i][col] == num:
            return False
    
    # 检查宫格
    box_size = int(size ** 0.5)
    start_row, start_col = box_size * (row // box_size), box_size * (col // box_size)
    for i in range(box_size):
        for j in range(box_size):
            if board[start_row + i][start_col + j] == num:
                return False
    
    return True

def solve_sudoku(board, size):
    for row in range(size):
        for col in range(size):
            if board[row][col] == 0:
                for num in range(1, size + 1):
                    if is_valid(board, row, col, num, size):
                        board[row][col] = num
                        if solve_sudoku(board, size):
                            return True
                        board[row][col] = 0
                return False
    return True

def sudoku_problem():
    size = int(input().strip())
    board = []
    for _ in range(size):
        row = list(map(int, input().split()))
        board.append(row)
    
    # 解数独
    solve_sudoku(board, size)
    
    # 输出结果
    for i in range(size):
        print(' '.join(map(str, board[i])))

# 主程序
def main():
    print("请选择要解决的问题：")
    print("1. 排序算法")
    print("2. 数独解题")
    
    choice = input("请输入选择 (1 或 2): ")
    
    if choice == '1':
        sorting_problem()
    elif choice == '2':
        sudoku_problem()
    else:
        print("无效选择")

if __name__ == "__main__":
    main()