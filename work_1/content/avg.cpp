#include <iostream>
#include <fstream>
#include <cstdlib>  
#include <ctime>  
#include <vector> 
using namespace std;

int main() {
    ofstream input("input.txt");
    if (!input) {
        cerr << "无法创建或打开input.txt文件！" << endl;
        return 1;
    }
    srand(time(0)); 
    for (int i = 0; i < 5; i++) {
        unsigned int rNum = rand() * RAND_MAX + rand();
        input << rNum;
        cout << rNum;
        if (i != 4) {
            input << " ";
            cout << " ";
        }
    }
    input << endl;
    cout << endl;
    ifstream output("input.txt");
    if (!output) {
        cerr << "无法打开input.txt文件！" << endl;
        return 1;
    }
    vector<unsigned int> nums;
    unsigned int num;
    while (output >> num) {
        nums.push_back(num);
    }
    output.close();
    if (nums.empty()) {
        cerr << "input.txt文件中没有有效的数据！" << endl;
        return 1;
    }
    float sum = 0.0;
    for (int i = 0; i < nums.size(); i++) {  
        sum += nums[i];
    }
    float avg = sum / nums.size();
    ofstream resFile("output.txt");
    if (!resFile) {
        cerr << "无法创建或打开output.txt文件！" << endl;
        return 1;
    }
    resFile << "平均数：" << avg << endl;
    cout << "平均数：" << avg << endl;
    cout << "计算完成！结果已保存到output.txt" << endl;
    return 0;
}