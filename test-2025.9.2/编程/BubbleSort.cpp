#include<iostream>
#include<vector>
using namespace std;
void BubbleSort(vector<double> &x) {
	for (int i = 0; i < x.size() - 1; i++) {
		bool flag = false;
		for (int j = 0; j < x.size() - 1 - i; j++) {
			if (x[j] > x[j + 1]) {
				int number = x[j];
				x[j] = x[j + 1];
				x[j + 1] = number;
				flag = true;
			}
		}
		if (flag == false) break;
	}
}
int main() {
	int n;
	int num;
	vector<double>  v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
	}
	BubbleSort(v);
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	return 0;
}
