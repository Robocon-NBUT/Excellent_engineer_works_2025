#include<iostream>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;
int main() {
	fstream ifs;
	ofstream ofs;
	ifs.open("input.txt", ios::out);
	ofs.open("output.txt", ios::out);
	vector<int> ve;
	srand(time(0));
	for (int a = 0; a < 5; a++) {
		int mu = rand();
		ifs << mu << " ";
	}
	ifs.close();
	ifs.open("input.txt", ios::in);
	double avea=0;
	int mun;
	while (ifs >> mun) {
		ve.push_back(mun);
	}
	ifs.close();
	for (int a : ve) {
		avea += a;
	}
	avea = avea / ve.size();
	ofs <<avea;
	cout << avea;
	ofs.close();
}