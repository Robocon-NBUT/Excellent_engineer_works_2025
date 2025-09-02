#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int num[100000]={0};
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(num[j]>num[j+1]){
                int temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
    for(int j=0;j<n;j++){
        cout<<num[j]<<" ";
    }
    return 0;
}

