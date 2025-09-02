#include <iostream>
#include <fstream>
using namespace std;
int main(){
	ofstream out("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\input.txt.txt");
	out<<5<<' '<<4<<' '<<3<<' '<<2<<' '<<1;
	ifstream in("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\input.txt.txt") ;
	int a,b,c,d,e,sum,s;
	in>>a>>b>>c>>d>>e;
	cout<<a<<b<<c<<d<<e<<endl;
	sum=a+b+c+d+e;
	s=sum/5;
	ofstream input("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\output.txt.txt");
	cout<<s;
	return 0;
}
