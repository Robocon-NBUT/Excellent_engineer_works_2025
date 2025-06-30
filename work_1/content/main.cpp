#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	//设置随机数种子 
	srand(static_cast<unsigned int>(time(nullptr)));
	//打开文件准备向其中写入数据 
	ofstream output("input.txt");
	//判断文件是否成功打开 
	if (!output.is_open()) {
		cerr << "文件创建失败！";
		return 1;
	} 
	//生成5个随机数并按空格分隔写入文件 
	for (int i = 0; i < 5; i++) {
		int tmp = 1 + rand() % 100;
		if (i == 0) {
			output << tmp;
		} else {
			output << " " << tmp;
		}
	}
	//关闭文件 
	output.close();
	//打开文件中北读取数据 
	ifstream input("input.txt");
	//判断文件是否成功打开 
	if (!input.is_open()) {
		cerr << "文件打开失败！";
		return 1;
	} 
	//将文件中数据存储到向量中 
	vector<unsigned int> v;
	while(!input.eof()) {
		int tmp;
		input >> tmp;
		v.push_back(tmp);
	}
	//关闭文件 
	input.close(); 
	//遍历向量并按空格分隔输出其中元素 
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cout << v[i];
		} else {
			cout << " " << v[i];
		}
	}
	//换行 
	cout << endl;
	//打开文件并准备从中读取数据 
	input.open("input.txt");
	//判断文件是否成功打开 
	if (!input.is_open()) {
		cerr << "文件打开失败！";
		input.close();
		return 1;
	}
	//计算文件中元素之和和个数 
	int sum = 0, cnt = 0;
	while (!input.eof()) {
		int tmp;;
		input >> tmp;
		sum += tmp;
		cnt++;
	}
	//关闭文件 
	input.close();
	//根据sum和cnt计算average 
	float average = sum * 1.0 / cnt;
	//创建文件并准备向其中输入数据 
	output.open("output.txt");
	//判断文件是否成功打开 
	if (!output.is_open()) {
		cerr << "文件创建失败";
		return 1;
	}
	//向文件中输入平均数 
	output << average;
	//关闭文件 
	output.close();
	//打开文件并准备从中读取数据 
	input.open("output.txt");
	//判断文件是否成功打开 
	if (!input.is_open()) {
		cerr << "文件打开失败！";
		return 1;
	}
	//读取文件中数据并将其存入向量中 
	vector<float> v1;
	while(!input.eof()) {
		float tmp;
		input >> tmp;
		v1.push_back(tmp);
	}
	//遍历向量并按空格分割输出其中元素，实际上就是输出平均值 
	for (int i = 0; i < v1.size(); i++) {
		if (i == 0) {
			cout << v1[i];
		} else {
			cout << " " << v1[i];
		}
	}
	return 0;
}
