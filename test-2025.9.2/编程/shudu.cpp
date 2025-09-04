#include <iostream>
using namespace std;

int n; // 数独大小（4或9）
int board[9][9]; // 存储数独，最大支持9x9

// 检查数字num放在(row, col)位置是否合法
bool check(int row, int col, int num) {
    // 检查行和列
    for (int i = 0; i < n; i++) {
        if (board[row][i] == num || board[i][col] == num)
            return false;
    }
    
    // 检查所在小宫格
    int size = (n == 4) ? 2 : 3; // 4阶宫格大小为2，9阶为3
    int startRow = (row / size) * size;
    int startCol = (col / size) * size;
    for (int i = startRow; i < startRow + size; i++) {
        for (int j = startCol; j < startCol + size; j++) {
            if (board[i][j] == num)
                return false;
        }
    }
    return true;
}

// 递归求解数独
bool solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) { // 找到空格
                for (int num = 1; num <= n; num++) { // 尝试填入1到n
                    if (check(i, j, num)) {
                        board[i][j] = num;
                        if (solve()) return true; // 成功则返回
                        board[i][j] = 0; // 失败则回溯
                    }
                }
                return false; // 无可用数字，返回失败
            }
        }
    }
    return true; // 填满所有空格，求解成功
}

int main() {
    cin >> n; // 输入4或9
    // 读取数独（0表示空格）
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    
    solve(); // 求解数独
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
