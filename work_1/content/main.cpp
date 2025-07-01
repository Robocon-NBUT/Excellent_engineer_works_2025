#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include <stdint.h>
#include <iomanip> 
using namespace std;
int main(){
	srand(time(0));
	ofstream ofs("input.txt");
	for(int i=0;i<5;i++){
		uint32_t num = (static_cast<uint32_t>(rand()) << 16) | rand();	
		if(i!=0){
			ofs<<" "<<num;
			cout<<" "<<num; 
		}else{
			ofs<<num;
			cout<<num;
		}	
	}
	ofs.close();
	cout<<"\n�����������"<<endl;
	uint64_t num_sum=0;
	double num_mid=0;
	ifstream ifs("input.txt");
	uint32_t num=0;
	while(ifs>>num){	
		num_sum+=num;
	}
	ifs.close();
	num_mid=static_cast<double>(num_sum) / 5.0;
	cout<<"��������ƽ����Ϊ��"<<fixed<<setprecision(1)<<num_mid<<endl;
	ofstream f("output.txt",ios::app);
	f<<"ƽ����Ϊ��"<<fixed<<setprecision(1)<<num_mid<<endl; 
	f.close();
	cout<<"������ƽ����"<<endl; 
	return 0;
} 
