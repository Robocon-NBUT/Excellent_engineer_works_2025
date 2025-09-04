#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> a;
void quickSort(vector<int>& arr, int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    int pivot = arr[left]; 
    while (i < j) {
        while (i < j && arr[j] >= pivot) j--; 
        if (i < j) arr[i++] = arr[j];
        while (i < j && arr[i] <= pivot) i++;
        if (i < j) arr[j--] = arr[i];
    }
    arr[i] = pivot;
    quickSort(arr, left, i - 1);
    quickSort(arr, i + 1, right);
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }
    cout << endl; 
    quickSort(a, 0, n -1); 
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}

