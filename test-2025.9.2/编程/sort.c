#include <stdio.h>
#include <stdlib.h>

// 快速排序函数
void quickSort(int arr[], int left, int right) {
    if (left >= right) return;
    
    int pivot = arr[(left + right) / 2]; // 选择中间元素作为基准
    int i = left, j = right;
    
    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            // 交换元素
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    
    // 递归排序左右两部分
    quickSort(arr, left, j);
    quickSort(arr, i, right);
}

int main() {
    int n;
    scanf("%d", &n);
    
    int* arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    quickSort(arr, 0, n - 1);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    free(arr);
    return 0;
}