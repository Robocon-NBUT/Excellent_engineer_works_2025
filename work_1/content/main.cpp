#include<bits/stdc++.h>
using namespace std;
int main(){
	srand(time(0));
	int a[5];
	int temp;
	int cnt=0;
	double sum=0;
	for(int i=0;i<5;i++){
		a[i]=rand();
	}
	fstream f1("input.txt",ios::out);
	for(int i=0;i<5;i++){
		f1<<a[i]<<" ";
	}
	f1.close();
	fstream f2("input.txt",ios::in);
	fstream f3("output.txt",ios::out);
	while(f2>>temp){
		sum+=temp;
		cnt++; 
	}
	sum/=cnt;
	f3<<sum;
	f2.close();
	f3.close();
} 
