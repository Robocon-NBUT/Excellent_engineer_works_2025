#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>  // ȷ��uint32_t����

int main() {
    // 1. ����������32λ����� (0~4294967295)
    srand((unsigned)time(NULL));
    uint32_t nums[5];
    for (int i = 0; i < 5; i++) {
        nums[i] = (uint32_t)rand() << 16 | rand();  // �������16λ�����
    }

    // 2. д���ļ�����ӡ����ȫһ�¸�ʽ��
    FILE* fp = fopen("input.txt", "w");
    printf("���ɵ������: ");
    for (int i = 0; i < 5; i++) {
        fprintf(fp, "%u ", nums[i]);  // %u ƥ��uint32_t
        printf("%u ", nums[i]);
    }
    fclose(fp);
    printf("\n");

    // 3. ��ȡ������float32��ֵ
    fp = fopen("input.txt", "r");
    float sum = 0.0f;  // ��ʽ����Ϊ32λfloat
    uint32_t val;
    for (int i = 0; i < 5; i++) {
        if (fscanf(fp, "%u", &val) != 1) {  // ��ȫ���
            printf("��ȡ����\n");
            return 1;
        }
        sum += (float)val;  // ��ʽת��Ϊfloat32
    }
    fclose(fp);

    // 4. ������������float32���ȣ�
    float mean = sum / 5.0f;  // ʹ��float����
    fp = fopen("output.txt", "w");
    fprintf(fp, "%.2f", mean);
    fclose(fp);
    printf("�����ֵ: %.2f\n", mean);

    return 0;
}