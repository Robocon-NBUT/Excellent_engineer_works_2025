#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){	
	double sum=0;
    int ch[5];
	int i=0;
	srand(time(NULL));
	FILE*pf=fopen("input.txt","w");
	for(int i=0;i<5;i++)
	{
		ch[i]=rand()%100;
		fprintf(pf,"%d ",ch[i]);
		printf("%d ",ch[i]);
		sum=sum+ch[i];
	}
	fclose(pf);
	double avg=sum/5;
	printf("\n%.2f",avg);
	FILE*pf2=fopen("output.txt","w");
	fprintf(pf2,"%f",sum/5);
	fclose(pf2);
	return 0;
}
