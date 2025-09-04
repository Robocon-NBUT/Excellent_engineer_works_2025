#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// ѡ��������
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // ��δ���򲿷�Ѱ����СԪ��
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ������СԪ�ص���ǰλ��
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    // ��ȡ��һ�У����г���
    cin >> n;
    cin.ignore(); // ���Ի��з�

    string line;
    // ��ȡ�ڶ��У�����Ԫ��
    getline(cin, line);

    vector<int> arr;
    stringstream ss(line);
    int num;

    // �����ո�ָ�������
    while (ss >> num) {
        arr.push_back(num);
    }

    // ������볤���Ƿ�ƥ��
    if (arr.size() != n) {
        cout << "�����������г�����ָ�����Ȳ�ƥ��" << endl;
        return 1;
    }

    // ʹ��ѡ�����������������
    selectionSort(arr);

    // ������������Կո�ָ�
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}