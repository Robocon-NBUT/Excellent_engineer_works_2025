#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 初始化随机数种子
    srand(time(NULL));

    // 打开文件以写入
    FILE* file = fopen("input.txt", "w");

    // 生成并写入五个随机数
    for (int i = 0; i < 5; i++) {
        // 生成32位无符号整数
        unsigned int num = (unsigned int)rand() << 16 | rand();

        // 写入文件
        fprintf(file, "%u", num);
        if (i < 4) {
            fprintf(file, " ");
        }

        // 打印到终端
        printf("%u", num);
        if (i < 4) {
            printf(" ");
        }
    }
    printf("\n");

    // 关闭文件
    fclose(file);

    // 打开input.txt以读取数据
    file = fopen("input.txt", "r");

    // 读取数据并计算均值
    unsigned int numbers[5];
    float sum = 0.0f;

    for (int i = 0; i < 5; i++) {
        fscanf(file, "%u", &numbers[i]);
        sum += (float)numbers[i];
    }

    float mean = sum / 5.0f;

    // 关闭input.txt
    fclose(file);

    // 打开output.txt以写入均值
    file = fopen("output.txt", "w");
    fprintf(file, "均值：%.6f", mean);
    fclose(file);

    // 在终端打印均值
    printf("均值: %.6f\n", mean);

    return 0;
}