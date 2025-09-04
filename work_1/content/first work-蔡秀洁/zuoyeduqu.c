#include<stdio.h>  
#include<stdlib.h>  //用于定义rand和srand
#include<time.h>    //用于time
int main(){
    FILE*pf=fopen("input.txt","w");
    if(pf==NULL){
        perror("无法打开文件");
        return 1;
    }
    srand(time(NULL));//初始化随机数种子
    printf("生成的随机生成数：");
    for(int i=0;i<5;i++) {
        int num=rand()%10;  //生成0-9的随机生成数
        fprintf(pf,"%d ",num);  //写入文件中
        printf("%d ",num);
    }
    fclose(pf);
    FILE*pf2=fopen("input.txt","r");
    int arr[5];
    int i=0;
    int sum=0;
    while(fscanf(pf2,"%d",&arr[i])==1&&i<5){
        sum+=arr[i];
        i++;
    }
    fclose(pf2);
    if(i==0){
        printf("文件中没有有效数字");
        return 1;
    }
    int mean=sum/i;
    FILE*pf3=fopen("output.txt","w");
    if(pf3==NULL){
        perror("无法打开文件");
        return 1;
    }
    fprintf(pf3,"%d\n",mean);
    fclose(pf3);
    pf3=NULL;
    return 0;
}