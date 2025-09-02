#include <iostream>
using namespace std;
int n;
int arr[100];
void bubble_sort() {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	
	bubble_sort();
	
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
