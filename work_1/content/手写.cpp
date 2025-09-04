#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main() {
	FILE* f;
	unsigned int n;
	float sum = 0;
	f = fopen("input.txt", "w");
	srand(time(NULL));
	for (int i = 0; i < 5; i++) {
		n = rand();
		fprintf(f, "%u ", n);
		printf("%u ", n);
	}
	fclose(f); 
	printf("\n");
	f = fopen("input.txt", "r");
	for (int i=0; i < 5; i++) {
		fscanf(f, "%u", &n);
		sum += n;
	}
	fclose(f);
	float pj = sum/ 5;
	f = fopen("output.txt", "w");
	fprintf(f, "平均数是%.2f", pj);
	printf("平均数是%.2f", pj);
	fclose(f);
	return 0;
	
}