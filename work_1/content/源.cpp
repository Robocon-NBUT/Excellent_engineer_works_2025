#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<random>
using namespace std;
//�������
int random_in_range(int min, int max) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(min, max);
	return distrib(gen);
}
//��ȡ�ļ���ֵ
vector<double> readfile(string filename) {
	ifstream fin(filename,ios::in);
	vector<double> data;
	string line;
	while (fin >> line) {
		data.push_back(stod(line));
	}
	fin.close();
	return data;
}
//д���ļ�����
void writefile(string filename, vector<int>& data) {
	ofstream fout(filename, ios::app);
	for (const int& num : data) {
		string s = to_string(num);
		fout << s << ' ';
	}
	fout.close();
}

double count_average(vector<double>& data) {
	double average = 0;
	for (auto& num : data) {
		average += num;
	}
	average /= data.size();
	return average;
}
int main()
{
	string input_name = R"(C:\Users\17989\Desktop\��ȡ�ļ�������������ƽ��ֵ��������ļ�\input.txt)";
	string output_name = R"(C:\Users\17989\Desktop\��ȡ�ļ�������������ƽ��ֵ��������ļ�\output.txt)";
	vector<int> data;
	for (int i = 0; i < 5; i++) {
		data.push_back(random_in_range(0, 100));
	}
	writefile(input_name, data);
	for (auto& num : data)
		cout << num << ' ';
	cout << endl;

	vector<double> arr = readfile(input_name);
	double average = count_average(arr);
	cout << average << endl;
	ofstream fout(output_name, ios::app);
	fout << "ƽ�����ǣ�" << average;
	fout.close();
}