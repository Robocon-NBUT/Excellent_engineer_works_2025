#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h> 
#define COUNT 5
int main() {
    srand((unsigned int)time(NULL)); 
    FILE *input_file = fopen("input.txt", "w");
    uint32_t numbers[COUNT];
    printf("生成的随机数: ");
    for (int i = 0; i < COUNT; i++) {
        numbers[i] = (uint32_t)rand(); 
        fprintf(input_file, "%u ", numbers[i]);
        printf("%u ", numbers[i]);
    }
    printf("\n");
    fclose(input_file);
    FILE *read_file = fopen("input.txt", "r");
    uint32_t read_numbers[COUNT];
    for (int i = 0; i < COUNT; i++) {
        fscanf(read_file, "%u", &read_numbers[i]);
    }
    fclose(read_file);
    float sum = 0.0f;
    for (int i = 0; i < COUNT; i++) {
        sum += (float)read_numbers[i];
    }
    float average = sum / (float)COUNT;
    FILE *output_file = fopen("output.txt", "w");
    fprintf(output_file, "%.2f", average);
    fclose(output_file);
    printf("计算的平均值: %.2f\n", average);
    return 0;
}