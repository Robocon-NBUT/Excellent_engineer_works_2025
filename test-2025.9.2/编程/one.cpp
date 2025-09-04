#include<bits/stdc++.h>
using namespace std;
void paixu(int*a,int n){
	int temp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(a[j]>a[j+1]){
			temp=a[j];
			a[j]=a[j+1];
			a[j+1]=temp;	
			}
		}
	}
}
int main(){
	int n;
	int temp; 
	vector<int> a;
	cin>>n;
    for(int i=0;i<n;i++){
    	cin>>temp;
    	a.push_back(temp);
	}
	paixu(&a[0],n);
	for(int i=0;i<n;i++){
		cout<<a[i]<<" "; 
	}
	
} 
