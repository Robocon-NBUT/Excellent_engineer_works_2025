#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int numbers[5];
    int sum = 0;

    for (int i = 0; i < 5; i++) {
        numbers[i] = rand() % 100 + 1;
        sum += numbers[i];
    }

    double average = (double)sum / 5;

    printf("生成的随机数: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n平均值: %.2f\n", average);

    return 0;
}
