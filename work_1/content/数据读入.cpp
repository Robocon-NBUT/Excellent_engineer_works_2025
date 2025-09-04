#include<iostream>
#include<fstream>
#include<cmath>
#include<vector>
#include<cstdlib>
#include<ctime> 
using namespace std;
int main(){
	srand (time(0));
 	unsigned int num[6]={0};
 	ofstream inputFile ("input.txt");
	for(int i=1;i<=5;i++){
	 	num[i]=rand();
	 	inputFile<<num[i]<<" ";
	}
	inputFile.close();
	for(int i=1;i<=5;i++){
		cout<<num[i]<<" ";
	}
	cout<<endl;
	double average=0;
	unsigned int num1=0;
	ifstream inputFileRead ("input.txt");
	while(inputFileRead>>num1){
		average+=num1;
	}
	inputFile.close();
	average/=5;
	ofstream outputFile ("output.txt");
	outputFile<<average;
	outputFile.close();
	cout<<average;
}

 
