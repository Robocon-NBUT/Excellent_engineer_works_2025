#include <bits/stdc++.h>
using namespace std;

int main() {
    // 生成五个随机数并写入 input.txt
    ofstream input("input.txt");
    vector<unsigned int> random_numbers(5);
    for (int i = 0; i < 5; ++i) {
        random_numbers[i] = rand() % 100 + 1;  // 随机数范围 1 到 100
        input << random_numbers[i] << " ";
    }
    input.close();

    // 打印在终端
    cout << "生成的随机数：";
    for (int i = 0; i < 5; ++i) {
        cout << random_numbers[i] << " ";
    }
    cout << endl;

    // 从 input.txt 读取数据并计算平均值
    ifstream input_read("input.txt");
    vector<unsigned int> data;
    unsigned int num;
    while (input_read >> num) {
        data.push_back(num);
    }
    input_read.close();

    // 计算平均值
    float sum = 0;
    for (unsigned int n : data) {
        sum += n;
    }
    float mean = sum / data.size();

    // 将平均值写入 output.txt
    ofstream output("output.txt");
    output << "数据的数量：" << data.size() <<endl; 
    output << "平均值: " << mean << endl;
    output.close();

    // 打印平均值到终端
    cout << "平均值: " << mean << endl;

    cout << "操作已完成" << endl;
    return 0;
}

