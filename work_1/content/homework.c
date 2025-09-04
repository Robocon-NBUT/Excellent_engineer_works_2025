#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define NUM_COUNT 5

int main() {
    // ��ʼ�����������
    srand(time(NULL));

    // ����5�������uint32_t����
    uint32_t numbers[NUM_COUNT];
    for (int i = 0; i < NUM_COUNT; i++) {
        numbers[i] = (uint32_t)rand() << 16 | rand(); // �������16λ�������32λ
    }

    // д��input.txt
    FILE* input_file = fopen("input.txt", "w");
    if (input_file == NULL) {
        perror("�޷���input.txt");
        return 1;
    }

    // ��ӡ���ն˲�д���ļ�
    printf("���ɵ������: ");
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

    // ��input.txt��ȡ����
    FILE* read_input = fopen("input.txt", "r");
    if (read_input == NULL) {
        perror("�޷���input.txt");
        return 1;
    }

    uint32_t read_numbers[NUM_COUNT];
    for (int i = 0; i < NUM_COUNT; i++) {
        if (fscanf_s(read_input, "%u", &read_numbers[i]) != 1) 
        {
            fprintf(stderr, "��ȡ����ʧ��\n");
            fclose(read_input);
            return 1;
        }
    }
    fclose(read_input);

    // �����ֵ��float32��
    float sum = 0.0f;
    for (int i = 0; i < NUM_COUNT; i++) {
        sum += (float)read_numbers[i];
    }
    float mean = sum / NUM_COUNT;

    // д��output.txt
    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("�޷���output.txt");
        return 1;
    }
    fprintf(output_file, "%.6f\n", mean); // ����6λС��
    fclose(output_file);

    // ��ӡ��ֵ���ն�
    printf("����õ��ľ�ֵ: %.6f\n", mean);

    return 0;
}