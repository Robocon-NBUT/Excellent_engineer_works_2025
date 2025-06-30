#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main() {
	int n = 5, count = 0;
	int sum = 0, x = 0;
	srand(time(0));
	FILE* fp = fopen("input.txt", "w");
	while (n--) {
		x = 1 + rand() % 1001;
		fprintf(fp, "%d ", x);
		printf("%d ", x);
	}
	fclose(fp);
	FILE* f = fopen("input.txt", "r");
	FILE* out = fopen("output.txt", "w");
	while (!feof(f)) {
		fscanf(f, "%d", &x);
		count++;
		sum += x;
	}
	int average = sum / count;
	fprintf(out, "%d", average);
	printf("\n%d", average);
	fclose(f);
	fclose(out);
	return 0;
}
