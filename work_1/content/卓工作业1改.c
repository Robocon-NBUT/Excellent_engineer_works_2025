#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>  // 确保uint32_t定义

int main() {
    // 1. 生成真正的32位随机数 (0~4294967295)
    srand((unsigned)time(NULL));
    uint32_t nums[5];
    for (int i = 0; i < 5; i++) {
        nums[i] = (uint32_t)rand() << 16 | rand();  // 组合两个16位随机数
    }

    // 2. 写入文件并打印（完全一致格式）
    FILE* fp = fopen("input.txt", "w");
    printf("生成的随机数: ");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%u ", nums[i]);  // %u 匹配uint32_t
        printf("%u ", nums[i]);
    }
    fclose(fp);
    printf("\n");

    // 3. 读取并计算float32均值
    fp = fopen("input.txt", "r");
    float sum = 0.0f;  // 显式声明为32位float
    uint32_t val;
    for (int i = 0; i < 5; i++) {
        if (fscanf(fp, "%u", &val) != 1) {  // 安全检查
            printf("读取错误\n");
            return 1;
        }
        sum += (float)val;  // 显式转换为float32
    }
    fclose(fp);

    // 4. 输出结果（保持float32精度）
    float mean = sum / 5.0f;  // 使用float运算
    fp = fopen("output.txt", "w");
    fprintf(fp, "%.2f", mean);
    fclose(fp);
    printf("计算均值: %.2f\n", mean);

    return 0;
}