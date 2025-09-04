#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

// 选择排序函数
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        // 在未排序部分寻找最小元素
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // 交换最小元素到当前位置
        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int n;
    // 读取第一行：序列长度
    cin >> n;
    cin.ignore(); // 忽略换行符

    string line;
    // 读取第二行：序列元素
    getline(cin, line);

    vector<int> arr;
    stringstream ss(line);
    int num;

    // 解析空格分隔的数字
    while (ss >> num) {
        arr.push_back(num);
    }

    // 检查输入长度是否匹配
    if (arr.size() != n) {
        cout << "错误：输入序列长度与指定长度不匹配" << endl;
        return 1;
    }

    // 使用选择排序进行升序排序
    selectionSort(arr);

    // 输出排序结果，以空格分隔
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}