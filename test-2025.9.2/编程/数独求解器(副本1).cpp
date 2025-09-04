#include <iostream>
#include <vector>
using namespace std;
int n;
vector<vector<int> > board;
bool isValid(int row, int col, int num) {
	for (int i = 0; i < n; i++) {
		if (board[row][i] == num) {
			return false;
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (board[i][col] == num) {
			return false;
		}
	}
	
	int size = (n == 4 ? 2 : 3);
	int startRow = row / size * size;
	int startCol = col / size * size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[startRow + i][startCol + j] == num) {
				return false;
			}
		}
	}
	
	return true;
}

bool backtracking() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 0) {
				for (int k = 1; k <= n; k++) {
					if (isValid(i, j, k)) {
						board[i][j] = k;
						if (backtracking()) return true;
						board[i][j] = 0;
					}
				}
				return false;
			}
		}
	}
	return true;
}
int main() {
	cin >> n;
	board.assign(n, vector<int>(n));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board[i][j];
		}
	}
	
	if (backtracking()) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}
	} else {
		cout << "нч╫Б" << endl; 
	}
	return 0;
}
