#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 5  // 定义要生成的数字个数

// 生成随机数并写入文件
void generate_random_numbers(const char* filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        perror("无法创建输入文件");
        exit(EXIT_FAILURE);
    }

    // 初始化随机数生成器
    srand((unsigned int)time(NULL));
    
    printf("生成的随机数: ");
    for (int i = 0; i < NUM_COUNT; i++) {
        unsigned int num = rand();
        fprintf(file, "%u", num);  // 写入文件
        
        // 数字间添加空格（最后一个数字后不加）
        if (i < NUM_COUNT - 1) {
            fprintf(file, " ");
        }
        
        printf("%u ", num);  // 打印到终端
    }
    printf("\n");
    
    fclose(file);
}

// 计算平均值
float calculate_average(const unsigned int* numbers, int count) {
    if (count == 0) {
        return 0.0f;
    }
    
    unsigned long sum = 0;
    for (int i = 0; i < count; i++) {
        sum += numbers[i];
    }
    
    return (float)sum / count;
}

int main() {
    const char* input_filename = "input.txt";
    const char* output_filename = "output.txt";
    
    // 1. 生成随机数并写入文件
    generate_random_numbers(input_filename);
    
    // 2. 从文件读取数据
    FILE* input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        perror("无法打开输入文件");
        return EXIT_FAILURE;
    }

    unsigned int numbers[NUM_COUNT];
    int count = 0;
    
    // 读取文件中的数字
    while (fscanf(input_file, "%u", &numbers[count]) == 1 && count < NUM_COUNT) {
        count++;
    }
    fclose(input_file);
    
    // 3. 计算平均值
    float average = calculate_average(numbers, count);
    
    // 4. 写入输出文件
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("无法创建输出文件");
        return EXIT_FAILURE;
    }
    fprintf(output_file, "%.2f", average);
    fclose(output_file);
    
    // 5. 终端打印结果
    printf("平均值: %.2f\n", average);
    
    return EXIT_SUCCESS;
}