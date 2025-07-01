#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    srand(time(0));

    vector <int> randomnumbers;
    for(int i = 0;i < 5;i++)
    {
    randomnumbers.push_back(rand()%100 + 1);
    }

    ofstream inputFile("input.txt");

    for(size_t i = 0; i < randomnumbers.size(); ++i)
    {
        inputFile << randomnumbers[i] << " ";
        cout << randomnumbers[i] << " ";
    }

    inputFile << endl;
    cout << endl;

    inputFile.close();

    vector <int> data;
    ifstream readFile("input.txt");

    int num;
    while(readFile >> num)
    {
        data.push_back(num);
    }

    readFile.close();

    double sum = 0;
    for(int num : data)
    {
        sum += num;
    
    }

    double n = sum / data.size();
    
    ofstream outputFile("output.txt");
    outputFile << n << endl;
    cout << n <<endl;
    outputFile.close();

    return 0;
}