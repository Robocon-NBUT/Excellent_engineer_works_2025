#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <cstdint>
using namespace std;
int main()
{
    // 初始化随机数生成器
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<uint32_t> dis(0, UINT32_MAX);
    // 生成5个32位无符号整数
    vector<uint32_t> arr;
    for(int i = 0; i < 5; i++) {
        uint32_t num = dis(gen);
        arr.push_back(num);
        cout << num << " ";
    }
    cout << endl;
    // 写入input.txt
    ofstream output("input.txt");
    if(!output) {
        cout << "无法打开文件" << endl;
        return 0;
    }
    for(uint32_t n : arr) {
        output << n << " ";
    }
    output.close();
    cout << "已保存以上数字到input.txt" << endl;

    // 从input.txt读取
    ifstream input("input.txt");
    if(!input) {
        cout << "无法打开文件" << endl;
        return 0;
    }
    vector<uint32_t> arr2;
    uint32_t x;
    while(input >> x) {
        arr2.push_back(x);
    }
    input.close();

    // 计算平均数
    uint64_t sum = 0;
    for(uint32_t n : arr2) {
        sum += n;
    }
    float average = static_cast<float>(sum) / arr2.size();

    // 写入output.txt（二进制格式）
    ofstream output2("output.txt", ios::binary);
    if(!output2) {
        cout << "无法打开文件" << endl;
        return 0;
    }
    output2.write(reinterpret_cast<const char*>(&average), sizeof(float));
    output2.close();

    cout << "这些数的平均数为：" << average << endl;
    cout << "结果已经写入output.txt（二进制格式）" << endl;

    return 0;
}