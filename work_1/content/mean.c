#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

float calculateMean(int data[], int n) {
    if (n <= 0) return data[n-1]; 
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    float mean = sum / n; 
    return mean;
}

int main() {
    FILE *inFile, *outFile;
    int data[1000]; 
    int n = 0;
    
    uint32_t nums[5];
    for (int i = 0; i < 5; i++) {
        nums[i] = (uint32_t)rand();
    }

    inFile = fopen("input.txt", "w");

    printf("数据为：");
    
    for (int i = 0; i < 5; i++) {
        fprintf(inFile, "%u\n", nums[i]);
        printf("%u%c", nums[i], i == 4 ? '\n' : ' '); 
    }
    
    fclose(inFile);

    inFile = fopen("input.txt", "r");

    while (n < 1000 && fscanf(inFile, "%u", (uint32_t*)&data[n]) == 1) {
        n++;
    }
    fclose(inFile);
    
    double mean = calculateMean(data, n);
    
    outFile = fopen("output.txt", "w");

    fprintf(outFile, "数据均值: %.4f\n", mean);
    fclose(outFile);
    printf("数据均值: %.4f\n", mean);
    return 0;
}