def is_valid(board, row, col, num, n):
    # 检查行
    for x in range(n):
        if board[row][x] == num:
            return False

    # 检查列
    for x in range(n):
        if board[x][col] == num:
            return False

    # 检查宫
    box_size = 2 if n == 4 else 3
    start_row, start_col = box_size * (row // box_size), box_size * (col // box_size)
    for i in range(box_size):
        for j in range(box_size):
            if board[start_row + i][start_col + j] == num:
                return False

    return True


def solve_sudoku(board, n):
    for row in range(n):
        for col in range(n):
            if board[row][col] == 0:
                for num in range(1, n + 1):
                    if is_valid(board, row, col, num, n):
                        board[row][col] = num

                        if solve_sudoku(board, n):
                            return True

                        board[row][col] = 0
                return False
    return True


def print_board(board, n):
    for i in range(n):
        print(" ".join(str(x) for x in board[i]))


def main():
    try:
        n = int(input().strip())
        if n not in [4, 9]:
            print("错误：请输入4或9")
            return

        board = []
        for i in range(n):
            row = list(map(int, input().split()))
            if len(row) != n:
                print(f"错误：第{i + 1}行应该有{n}个元素")
                return
            board.append(row)

        if solve_sudoku(board, n):
            print_board(board, n)
        else:
            print("无解")

    except ValueError:
        print("错误：请输入有效的数字")


if __name__ == "__main__":
    main()