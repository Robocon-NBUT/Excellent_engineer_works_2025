#include <iostream>
#include <vector>
#include <algorithm>

void quick_sort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }
    quick_sort(sequence, 0, n - 1);
    for (int i = 0; i < n; i++) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}