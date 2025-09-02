#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NUM_COUNT 5

int main() {
    // 初始化随机数种子
    srand(time(NULL));

    // 生成5个随机的uint32_t数字
    uint32_t numbers[NUM_COUNT];
    for (int i = 0; i < NUM_COUNT; i++) {
        numbers[i] = (uint32_t)rand() << 16 | rand(); // 组合两个16位随机数成32位
    }

    // 写入input.txt
    FILE* input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        perror("无法打开input.txt");
        return 1;
    }

    // 打印到终端并写入文件
    printf("生成的随机数: ");
    for (int i = 0; i < NUM_COUNT; i++) {
        fprintf(input_file, "%u", numbers[i]);
        printf("%u", numbers[i]);
        if (i < NUM_COUNT - 1) {
            fprintf(input_file, " ");
            printf(" ");
        }
    }
    fprintf(input_file, "\n");
    printf("\n");
    fclose(input_file);

    // 从input.txt读取数据
    FILE* read_input = fopen("input.txt", "r");
    if (read_input == NULL) {
        perror("无法打开input.txt");
        return 1;
    }

    uint32_t read_numbers[NUM_COUNT];
    for (int i = 0; i < NUM_COUNT; i++) {
        if (fscanf_s(read_input, "%u", &read_numbers[i]) != 1) 
        {
            fprintf(stderr, "读取数据失败\n");
            fclose(read_input);
            return 1;
        }
    }
    fclose(read_input);

    // 计算均值（float32）
    float sum = 0.0f;
    for (int i = 0; i < NUM_COUNT; i++) {
        sum += (float)read_numbers[i];
    }
    float mean = sum / NUM_COUNT;

    // 写入output.txt
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("无法打开output.txt");
        return 1;
    }
    fprintf(output_file, "%.6f\n", mean); // 保留6位小数
    fclose(output_file);

    // 打印均值到终端
    printf("计算得到的均值: %.6f\n", mean);

    return 0;
}