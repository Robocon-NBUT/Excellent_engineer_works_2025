#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define COUNT 5
int main()
{
	srand(time(NULL));
	FILE*file;
	unsigned int num;
	float sum=0;
	file=fopen("input.txt","w");
	if(!file)return perror("打开失败"),1;
	printf("生成的数：") ;
	for(int i=0;i<COUNT;i++){
		num=rand();
		fprintf(file,i<COUNT-1?"%u ":"%u",num);
		printf(i<COUNT-1?"%u ":"%u",num);
	}
	fclose(file);
	putchar('\n');
	file=fopen("input.txt","r");
	if(!file)return perror("打开失败"),1;
	for(int i=0;i<COUNT;i++){
		fscanf(file,"%u",&num);
		sum+=num;
	}
	fclose(file);
	float avg=sum/COUNT;
	file=fopen("output.txt","w");
	if(!file)return perror("打开失败"),1;
	fprintf(file,"%.4f",avg) ;
	fclose(file);
	printf("平均值：%.4f\n",avg);
	return 0;
}
