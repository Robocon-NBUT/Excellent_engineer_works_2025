#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void generate_random() {
    FILE* fp = fopen("input.txt", "w");
    if (fp == NULL) {
        perror("Failed to open input.txt");
        return;
    }
    srand((unsigned int)time(NULL));
    for (int i = 0; i < 5; ++i) {
        unsigned int num = (unsigned int)rand();
        fprintf(fp, "%u ", num);
        printf("%u ", num);
    }
    fclose(fp);
    printf("\n");
}
void calculate_average() {
    FILE* fp = fopen("input.txt", "r");
    if (fp == NULL) {
        perror("Failed to open input.txt");
        return;
    }
    unsigned int num;
    unsigned int sum = 0;
    int count = 0;
    while (fscanf(fp, "%u", &num) == 1) {
        sum += num;
        count++;
    }
    fclose(fp);
    float average = (float)sum / count;
    FILE* out_fp = fopen("output.txt", "w");
    if (out_fp == NULL) {
        perror("Failed to open output.txt");
        return;
    }
    fprintf(out_fp, "%.6f", average);
    fclose(out_fp);
    printf("%.6f\n", average);
}
int main() {
    generate_random();
    calculate_average();
    return 0;
}