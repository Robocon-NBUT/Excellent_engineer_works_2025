#include<iostream>
#include<ctime>
#include<fstream>
#include<vector>
using namespace std;
double pjs(const vector<int>& data) {
	double sum = 0;
	for (int num : data) {
		sum += num;
	}
	double size = data.size();
	return sum / size;
}
void display(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) {
		cout << "�޷����ļ�" << filename; return;
	}
	cout << "�ļ�" << filename << "�����ݣ�";
	string line;
	while (file >> line) {
		cout << line << " ";
	}
	file.close();
}
int main() {
	srand(time(0));
	vector<int>data;
	int num1 = 0;
	ofstream outfile1("input2.txt");
	while (num1 < 5) {
		int num = rand();
		data.push_back(num);
		num1++;
	}
	for (int num : data) {
		outfile1 << num << " ";
	}
	outfile1.close();
	display("input2.txt");
	ifstream infile2("input2.txt");
	ofstream outfile2("output2.txt");
	vector<int>data_test;
	if (!infile2.is_open()) {
		cout << "�ļ��޷���"; 
	}
	int num;
	while (infile2 >> num) {
		data_test.push_back(num);
	}
	double aaa = pjs(data_test);
	outfile2 << "ƽ������" << aaa;
	outfile2.close();
	infile2.close();
	display("output2.txt");
	return 0;
}