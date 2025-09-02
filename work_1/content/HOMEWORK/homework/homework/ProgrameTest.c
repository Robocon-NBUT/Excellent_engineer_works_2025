#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int i,j=0,a[5],b,sum=0;
	FILE* in, * out;
	srand((unsigned int)time(NULL));
	if ((in = fopen("C:\\Users\\36744\\Desktop\\newfile\\Excellent_engineer_Yaclum_works_2025\\work_1\\content\\HOMEWORK\\input.txt", "w")) == NULL) {
		printf("cannot");
		exit(0);
	}
	printf("in:\n");
	for (i = 0; i < 5; i++) {
		a[i] = rand();
		printf("%d ", a[i]);
		fprintf(in, "%d ", a[i]);
	}
	printf("\n");
	for (i = 0; i < 5; i++,j++) {
		fscanf(in, "%d ", &a[i]);
		//printf("%d ", a[i]);
		sum = sum + a[i];
		//printf("%d\n", sum);
	}
	b = sum/j;
	printf("out:\n");
	printf("%d", b);
	if ((out = fopen("C:\\Users\\36744\\Desktop\\newfile\\Excellent_engineer_Yaclum_works_2025\\work_1\\content\\HOMEWORK\\output.txt", "w")) == NULL) {
		printf("cannot");
		exit(0);
	}
	fprintf(out, "%d", b);
	fclose(in);
	fclose(out);
	return 0;
}