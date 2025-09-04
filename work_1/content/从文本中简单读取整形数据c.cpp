#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <inttypes.h> 
#include <time.h>

double calculateMean(int* data, int size) {
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

double calculateVariance(int* data, int size, double mean) {
    double variance = 0.0;
    for (int i = 0; i < size; i++) {
        variance += pow(data[i] - mean, 2);
    }
    return variance / size;
}

int main() {

	srand((unsigned int)time(NULL));
	    
	    FILE *fp = fopen("input.txt", "w");
	    if (!fp) {
	        perror("�ļ���ʧ��");
	        return EXIT_FAILURE;
	    }
	
	    printf("���ɵ��������");
	    for (int i = 0; i < 5; i++) {
	        uint32_t num = (uint32_t)rand() << 16 | (uint32_t)rand();
	        
	        // �ļ�д��
	        fprintf(fp, "%" PRIu32, num);
	        if (i < 4) fprintf(fp, " ");
	        
	        // �ն����
	        printf("%" PRIu32, num);
	        if (i < 4) printf(" ");
	    }
	    
	    printf("\n");
	    fclose(fp);
	
    FILE *inputFile = fopen("input.txt", "r");
    if (!inputFile) {
        perror("�޷��������ļ�");
        return 1;
    }

    int* numbers = NULL;
    int count = 0;
    int capacity = 10;
    numbers = (int*)malloc(capacity * sizeof(int));

    int num;
    while (fscanf(inputFile, "%d", &num) == 1) {
        if (count >= capacity) {
            capacity *= 2;
            numbers = (int*)realloc(numbers, capacity * sizeof(int));
        }
        numbers[count++] = num;
    }
    fclose(inputFile);

    if (count == 0) {
        printf("����Ч���ݣ�");
        free(numbers);
        return 1;
    }

    double mean = calculateMean(numbers, count);
    double variance = calculateVariance(numbers, count, mean);

    FILE *outputFile = fopen("output.txt", "w");
    fprintf(outputFile, "��ֵ: %.2f\n����: %.2f\n", mean, variance);
    fclose(outputFile);

    free(numbers);
    return 0;
}
