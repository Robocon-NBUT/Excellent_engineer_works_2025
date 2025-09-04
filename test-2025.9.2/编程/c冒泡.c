#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    int swapped;
    for (i = 0; i < n-1; i++) {
        swapped = 0;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // 交换 arr[j] 和 arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
            }
        }
        // 如果没有发生交换，说明数组已经有序
        if (swapped==0) {
            break;
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);

    int *nums = (int*)malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }
  
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }
    for (int i=0; i < n; i++)
        printf("%d ", nums[i]);
    printf("\n");
    bubble_sort(nums, n);
    for (int i=0; i < n; i++)    
        printf("%d ", nums[i]); 
    printf("\n");
    free(nums);

    return 0;
}