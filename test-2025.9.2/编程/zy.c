#include <stdio.h>

int main() {
    int n;
    printf("序列长度:");
    scanf("%d", &n);
    
    int a[n];
    printf("输入序列:");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(a[j] > a[j+1]) 
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    printf("结果序列:");
    for(int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if(i < n-1) 
        {
            printf(" ");
        }
    }
    printf("\n");
    
    return 0;
}