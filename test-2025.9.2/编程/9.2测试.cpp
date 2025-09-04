#include<stdio.h>
int main()
{
	int n,i,j;
	int data[10]={0};
	printf("ÊäÈëÅÅĞò¸öÊı£º"); 
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data[i]);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(data[j]>data[j+1])
			{
				int t=data[j];
				data[j]=data[j+1];
				data[j+1]=t;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		printf("%d ",data[i]);
	}
	return 0; 
 } 
