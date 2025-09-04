def is_valid(board, row, col, num, size):
    for c in range(size):
        if board[row][c] == num:
            return False
    for r in range(size):
        if board[r][col] == num:
            return False
    sub_size = int(size ** 0.5)
    start_row, start_col = row - row % sub_size, col - col % sub_size
    for r in range(start_row, start_row + sub_size):
        for c in range(start_col, start_col + sub_size):
            if board[r][c] == num:
                return Falserk
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

if __name__ == "__main__":
    size = int(input().strip())
    board = [list(map(int, input().strip().split())) for _ in range(size)]
    solve_sudoku(board, size)
    for row in board:
        print(" ".join(map(str, row)))
