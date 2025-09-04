#include<bits/stdc++.h>
using namespace std;

const int MAXSIZE=10086; 

void bubbleSort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}	
		} 
	}
}
int main()
{
	int size;
	cin>>size;
	int nums[MAXSIZE];
	
	for(int i=0;i<size;i++)cin>>nums[i];
	
	bubbleSort(nums,size);
	
	for(int i=0;i<size;i++){
		if(i!=0){
			cout<<" "<<nums[i];	
		}else{
			cout<<nums[i];
		}
	}
		
	return 0;
}
