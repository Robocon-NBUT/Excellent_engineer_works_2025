#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;
int main() {
	//������������� 
	srand(static_cast<unsigned int>(time(nullptr)));
	//���ļ�׼��������д������ 
	ofstream output("input.txt");
	//�ж��ļ��Ƿ�ɹ��� 
	if (!output.is_open()) {
		cerr << "�ļ�����ʧ�ܣ�";
		return 1;
	} 
	//����5������������ո�ָ�д���ļ� 
	for (int i = 0; i < 5; i++) {
		int tmp = 1 + rand() % 100;
		if (i == 0) {
			output << tmp;
		} else {
			output << " " << tmp;
		}
	}
	//�ر��ļ� 
	output.close();
	//���ļ��б���ȡ���� 
	ifstream input("input.txt");
	//�ж��ļ��Ƿ�ɹ��� 
	if (!input.is_open()) {
		cerr << "�ļ���ʧ�ܣ�";
		return 1;
	} 
	//���ļ������ݴ洢�������� 
	vector<unsigned int> v;
	while(!input.eof()) {
		int tmp;
		input >> tmp;
		v.push_back(tmp);
	}
	//�ر��ļ� 
	input.close(); 
	//�������������ո�ָ��������Ԫ�� 
	for (int i = 0; i < v.size(); i++) {
		if (i == 0) {
			cout << v[i];
		} else {
			cout << " " << v[i];
		}
	}
	//���� 
	cout << endl;
	//���ļ���׼�����ж�ȡ���� 
	input.open("input.txt");
	//�ж��ļ��Ƿ�ɹ��� 
	if (!input.is_open()) {
		cerr << "�ļ���ʧ�ܣ�";
		input.close();
		return 1;
	}
	//�����ļ���Ԫ��֮�ͺ͸��� 
	int sum = 0, cnt = 0;
	while (!input.eof()) {
		int tmp;;
		input >> tmp;
		sum += tmp;
		cnt++;
	}
	//�ر��ļ� 
	input.close();
	//����sum��cnt����average 
	float average = sum * 1.0 / cnt;
	//�����ļ���׼���������������� 
	output.open("output.txt");
	//�ж��ļ��Ƿ�ɹ��� 
	if (!output.is_open()) {
		cerr << "�ļ�����ʧ��";
		return 1;
	}
	//���ļ�������ƽ���� 
	output << average;
	//�ر��ļ� 
	output.close();
	//���ļ���׼�����ж�ȡ���� 
	input.open("output.txt");
	//�ж��ļ��Ƿ�ɹ��� 
	if (!input.is_open()) {
		cerr << "�ļ���ʧ�ܣ�";
		return 1;
	}
	//��ȡ�ļ������ݲ�������������� 
	vector<float> v1;
	while(!input.eof()) {
		float tmp;
		input >> tmp;
		v1.push_back(tmp);
	}
	//�������������ո�ָ��������Ԫ�أ�ʵ���Ͼ������ƽ��ֵ 
	for (int i = 0; i < v1.size(); i++) {
		if (i == 0) {
			cout << v1[i];
		} else {
			cout << " " << v1[i];
		}
	}
	return 0;
}
