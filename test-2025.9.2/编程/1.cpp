#include <iostream>
using namespace std;
int a[10000000];

void print(int a[], int n) {
    for (int j = 0; j < n; j++) {
        cout << a[j] << ' ';
    }
    cout << endl;
}

void qsort(int a[], int l, int r) {
    int i = l, j = r, flag = a[(l + r) / 2], tmp;
    do {
        while (a[i] < flag) i++;
        while (a[j] > flag) j--;
        if (i <= j) {
            tmp = a[i]; a[i] = a[j]; a[j] = tmp;
            i++; j--;
        }
    } while (i <= j);
    if (l < j)qsort(a, l, j);
    if (i < r)qsort(a, i, r);
}


int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    qsort(a, 0, n - 1);
    print(a, n);
    return 0;
}