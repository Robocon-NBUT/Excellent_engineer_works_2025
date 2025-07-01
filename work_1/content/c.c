#include <stdio.h>
#include <stdlib.h>   // 用于rand()和srand()
#include <time.h>     // 用于time()
#include <stdint.h>   // 用于uint32_t和精确类型定义

int main() {
    FILE *file;
    uint32_t num;
    int count = 0;
    float sum = 0.0f, mean;  // 使用float保证32位浮点数

    // 1. 生成5个随机数并写入input.txt
    file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("无法创建文件input.txt！\n");
        return 1;
    }

    srand(time(NULL));  // 初始化随机数种子
    printf("生成的随机数: ");
    for (int i = 0; i < 5; i++) {
        num = rand();  // 生成随机数（范围是0到RAND_MAX）
        fprintf(file, "%u ", num);  // 写入文件，空格分隔
        printf("%u ", num);         // 打印到终端
    }
    printf("\n");
    fclose(file);

    // 2. 从input.txt读取数据并计算平均值
    file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("无法打开文件input.txt！\n");
        return 1;
    }

    while (fscanf(file, "%u", &num) == 1) {
        sum += num;
        count++;
    }
    mean = sum / count;  // 计算平均值

    fclose(file);

    // 3. 将结果写入output.txt并打印到终端
    file = fopen("output.txt", "w");
    if (file == NULL) {
        printf("无法创建文件output.txt！\n");
        return 1;
    }

    fprintf(file, "平均值: %.2f\n", mean);
    printf("平均值: %.2f\n", mean);
    fclose(file);

    return 0;
}