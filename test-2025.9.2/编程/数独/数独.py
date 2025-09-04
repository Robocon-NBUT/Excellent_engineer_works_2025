def is_valid(board, row, col, num, size):
    for i in range(size):
        if board[row][i] == num or board[i][col] == num:
            return False
    start_row, start_col = row - row % int(size**0.5), col - col % int(size**0.5)
    for i in range(int(size**0.5)):
        for j in range(int(size**0.5)):
            if board[i + start_row][j + start_col] == num:
                return False
    return True

def solve_sudoku(board, size):
    empty = None
    for i in range(size):
        for j in range(size):
            if board[i][j] == 0:
                empty = (i, j)
                break
        if empty:
            break
    if not empty:
        return True
    row, col = empty
    for num in range(1, size + 1):
        if is_valid(board, row, col, num, size):
            board[row][col] = num
            if solve_sudoku(board, size):
                return True
            board[row][col] = 0
    return False

def print_board(board):
    for row in board:
        print(' '.join(map(str, row)))

def main():
    size = int(input())
    board = []
    for _ in range(size):
        board.append(list(map(int, input().split())))
    if solve_sudoku(board, size):
        print_board(board)
    else:
        print("No solution exists")

if __name__ == "__main__":
    main()