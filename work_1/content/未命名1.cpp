#include <bits/stdc++.h>
using namespace std;

int main() {
    // ��������������д�� input.txt
    ofstream input("input.txt");
    vector<unsigned int> random_numbers(5);
    for (int i = 0; i < 5; ++i) {
        random_numbers[i] = rand() % 100 + 1;  // �������Χ 1 �� 100
        input << random_numbers[i] << " ";
    }
    input.close();

    // ��ӡ���ն�
    cout << "���ɵ��������";
    for (int i = 0; i < 5; ++i) {
        cout << random_numbers[i] << " ";
    }
    cout << endl;

    // �� input.txt ��ȡ���ݲ�����ƽ��ֵ
    ifstream input_read("input.txt");
    vector<unsigned int> data;
    unsigned int num;
    while (input_read >> num) {
        data.push_back(num);
    }
    input_read.close();

    // ����ƽ��ֵ
    float sum = 0;
    for (unsigned int n : data) {
        sum += n;
    }
    float mean = sum / data.size();

    // ��ƽ��ֵд�� output.txt
    ofstream output("output.txt");
    output << "���ݵ�������" << data.size() <<endl; 
    output << "ƽ��ֵ: " << mean << endl;
    output.close();

    // ��ӡƽ��ֵ���ն�
    cout << "ƽ��ֵ: " << mean << endl;

    cout << "���������" << endl;
    return 0;
}

