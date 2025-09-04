#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	FILE*pf = fopen("input.txt","w");
	srand((unsigned int)time(NULL));
	int j=0;
	int randomNums[5];
	for(j=0;j<5;j++)
	{
		int num=rand() %100;
		randomNums[j]=num;
		fprintf(pf,"%d ",num);
	}
	fclose(pf);
	double sum=0;
	int count=5;
	float ch[100];
	FILE*pf_read = fopen("input.txt","r");
	int i=0;
	for(i=0;i<count;i++)
	{
		fscanf(pf_read,"%f",&ch[i]);
		sum+=ch[i];
	}
	fclose(pf_read);
	double avg=sum/count;
	FILE* pf2 = fopen("output.txt","w");
	fprintf(pf2,"%f",avg);
	fclose(pf2);
	for (j=0;j<5;j++)
	{
		printf("%d ",randomNums[j]);
	}
	printf("\n");
	printf("%21.f\n",avg);
	return 0;
}

