#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*in,*out;
	float ave;
	unsigned int num[5],sum;
	int i;
	srand((unsigned int)time(NULL));
	in=fopen("input.txt","w");
	out=fopen("output.txt","w");
	i=0;sum=0;
	for (i = 0; i < 5; i++)
	 {
         num[i] = rand();
         fprintf(in, "%u ", num[i]);
         printf("%u ", num[i]);
         sum += num[i];
     }
	ave=(float)sum/i;
	printf("\n%.2f ", ave);
	fprintf(out,"%.2f",ave);
	fclose(in);
	fclose(out);
	return 0;
	} 
