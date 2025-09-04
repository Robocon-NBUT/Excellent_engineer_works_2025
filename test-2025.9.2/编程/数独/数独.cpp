#include <iostream>
#include <vector>
#include <cmath>

bool is_valid(std::vector<std::vector<int>>& board, int row, int col, int num, int size) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    int start_row = row - row % static_cast<int>(sqrt(size));
    int start_col = col - col % static_cast<int>(sqrt(size));
    for (int i = 0; i < static_cast<int>(sqrt(size)); i++) {
        for (int j = 0; j < static_cast<int>(sqrt(size)); j++) {
            if (board[i + start_row][j + start_col] == num) {
                return false;
            }
        }
    }
    return true;
}

bool solve_sudoku(std::vector<std::vector<int>>& board, int size) {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty) {
            break;
        }
    }
    if (isEmpty) {
        return true;
    }
    for (int num = 1; num <= size; num++) {
        if (is_valid(board, row, col, num, size)) {
            board[row][col] = num;
            if (solve_sudoku(board, size)) {
                return true;
            }
            board[row][col] = 0;
        }
    }
    return false;
}

void print_board(const std::vector<std::vector<int>>& board) {
    for (const auto& row : board) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int size;
    std::cin >> size;
    std::vector<std::vector<int>> board(size, std::vector<int>(size));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> board[i][j];
        }
    }
    if (solve_sudoku(board, size)) {
        print_board(board);
    }
    else {
        std::cout << "wujie" << std::endl;
    }
    return 0;
}