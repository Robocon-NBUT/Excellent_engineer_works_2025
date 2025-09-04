#include <stdio.h>

#define N9 9
#define N4 4

int n;  
int board[9][9];  


int isValid(int row, int col, int num) {
    int blockSize = (n == 9) ? 3 : 2;
    for (int i = 0; i < n; i++) {
        if (board[row][i] == num) return 0;
        if (board[i][col] == num) return 0;
    }
    int startRow = (row / blockSize) * blockSize;
    int startCol = (col / blockSize) * blockSize;
    for (int i = 0; i < blockSize; i++) {
        for (int j = 0; j < blockSize; j++) {
            if (board[startRow + i][startCol + j] == num) return 0;
        }
    }
    return 1;
}


int solveSudoku() {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == 0) {
                for (int num = 1; num <= n; num++) {
                    if (isValid(row, col, num)) {
                        board[row][col] = num;
                        if (solveSudoku()) return 1;
                        board[row][col] = 0; 
                    }
                }
                return 0; 
            }
        }
    }
    return 1; 
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    if (solveSudoku()) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", board[i][j]);
                if (j != n - 1) printf(" ");
            }
            printf("\n");
        }
    } else {
        printf("No solution\n");
    }
    return 0;
}
