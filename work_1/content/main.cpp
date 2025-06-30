#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>

using namespace std;

double mean(const vector<int>& data) {
    double mean = 0.0;
    for (int num : data){ 
        mean += num;
    }
    return mean / data.size();
}

int main() {
    srand(time(0));
    ofstream input("input.txt");
    for (int i = 0; i < 5; i++) {
        int num=rand();
        cout << num << ' ';
        input << num << ' ';
    }
    cout << endl;
    input.close();

    ofstream output("output.txt");
    vector<int> data;
    int num;
    ifstream input2("input.txt");
    while (input2 >> num) {
        data.push_back(num);
    }
    double r = mean(data);
    output << r << endl;
    cout << r;
    input.close();
    output.close();
    return 0;
}