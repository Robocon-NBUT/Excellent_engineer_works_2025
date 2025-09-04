#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
double pjs(const vector<int>& data) {
    int size = data.size();
    if (size == 0) { return 0; }
    double sum = 0;
    for (int value : data) {
        sum += value;
    }
    double average = sum / size;  
    return  average;
}
void display(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "无法打开文件 " << filename << endl;
        return;
    }
    string line;
    cout << "\n" << filename << " 的内容：" << endl;
    while (file>> line) {
        cout << line <<" ";
    }
    file.close();
}
int main() {   
    ofstream outFile1("input.txt");
    vector<int>Data;
    int num;
    srand(time(0));
    int num1 = 0;
    while (num1 < 5) {
        num = rand();
        Data.push_back(num);
        num1++;
    }
    for (int value : Data) {
        outFile1 << value <<" ";
    }

   
    outFile1.close();
  

    ifstream inFile("input.txt");
    ofstream outFile2("output.txt");
    vector<int> fileData;

    if (!inFile.is_open()) {
        cerr << "无法打开文件 1.txt" << endl;
        return 1;
    }

    int num2;
    while (inFile>>num2) {
        fileData.push_back(num2);
    }  
    double pj = pjs(fileData);
    outFile2 << "平均数: " << pj << endl; 
    inFile.close();
    outFile2.close();
    display("input.txt"); 
    display("output.txt");
    return 0;
}