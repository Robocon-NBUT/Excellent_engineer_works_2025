#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
int main()
{
    //创建文件，并输入5个随机数
    ofstream outFile("in.txt",ios::out);
    if(outFile.is_open() == false)
    {
        cerr << "in.txt文件打开错误" << endl;
    }
    srand(time(0));
    for(int i = 0; i < 5;i++)
    {
        unsigned int m = rand();
        outFile << m << " ";
    }
    outFile.close();


    //读取文件数据，并计算方差
    double sum = 0;
    double temp;
    float avg;
    vector<double> shuju;
    ifstream inFile("in.txt",ios::in);
    if(inFile.is_open() == false)
    {
        cerr << "in.txt文件打开错误" << endl;
    }
    cout << "input:" << endl;
    while(inFile >> temp)
    {
        cout << temp << " ";
        sum += temp;
        shuju.push_back(temp);
    }
    cout << endl <<  "output:" << endl;
    avg = sum / shuju.size();
    ofstream outFile1("out.txt",ios::out);
    outFile1 << avg ;
    cout << avg << endl;
    inFile.close();
    return 0;   
}