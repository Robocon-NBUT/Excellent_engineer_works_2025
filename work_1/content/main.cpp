#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

int main() {
  
    srand(time(NULL));
    
  
    FILE *input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        perror("无法打开input.txt文件");
        return 1;
    }
    
    uint32_t numbers[5];
    printf("生成的随机数: ");
    for (int i = 0; i < 5; i++) {
        numbers[i] = rand();
        fprintf(input_file, i == 0 ? "%u" : " %u", numbers[i]);
        printf(i == 0 ? "%u" : " %u", numbers[i]);
    }
    printf("\n");
    fclose(input_file);
    
 
    input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        perror("无法打开input.txt文件");
        return 1;
    }
    
    float sum = 0.0f;
    for (int i = 0; i < 5; i++) {
        fscanf(input_file, "%u", &numbers[i]);
        sum += numbers[i];
    }
    fclose(input_file);
    
    float average = sum / 5.0f;
    
 
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("无法打开output.txt文件");
        return 1;
    }
    fprintf(output_file, "%f", average);
    fclose(output_file);
    
    printf("计算的平均值: %f\n", average);
    
    return 0;
}

