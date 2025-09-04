#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int> >& board, int row, int col, int num, int size) {
    for (int i = 0; i < size; i++) {
        if (board[row][i] == num) {
            return false;
        }
    }
    
    for (int i = 0; i < size; i++) {
        if (board[i][col] == num) {
            return false;
        }
    }
    
    int boxSize = sqrt(size);
    int startRow = row - row % boxSize;
    int startCol = col - col % boxSize;
    
    for (int i = 0; i < boxSize; i++) {
        for (int j = 0; j < boxSize; j++) {
            if (board[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    
    return true;
}

bool solveSudoku(vector<vector<int> >& board, int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= size; num++) {
                    if (isValid(board, row, col, num, size)) {
                        board[row][col] = num;
                        if (solveSudoku(board, size)) {
                            return true;
                        }
                        board[row][col] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    int sizeType;
    cin >> sizeType;
    
    vector<vector<int> > board(sizeType, vector<int>(sizeType));
    
    for (int i = 0; i < sizeType; i++) {
        for (int j = 0; j < sizeType; j++) {
            cin >> board[i][j];
        }
    }
    
    if (solveSudoku(board, sizeType)) {
        for (int i = 0; i < sizeType; i++) {
            for (int j = 0; j < sizeType; j++) {
                cout << board[i][j];
                if (j < sizeType - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    } else {
        cout << "No solution exists" << endl;
    }
    
    return 0;
}
