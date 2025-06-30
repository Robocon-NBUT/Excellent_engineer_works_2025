#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>

int main(){
    srand(time(NULL));
    int random_numbers[5];
    for(int i=0;i<5;i++){
        random_numbers[i]=rand()%101; //生成0-100的随机数
    }
    FILE *input_file=fopen("input.txt","w");
    for(int i=0;i<5;i++){
        fprintf(input_file,"%d",random_numbers[i]);
        if(i<4){
            fprintf(input_file," ");
        }
    }
    fclose(input_file);
    for(int i=0;i<5;i++){
        printf("%d\n",random_numbers[i]);
    }
    int sum=0;
    for(int j=0;j<5;j++){
        sum+=random_numbers[j];
    }
    float mean=0;
    mean=sum/5;
    printf("%f",mean);
    printf("%f",sum);
}