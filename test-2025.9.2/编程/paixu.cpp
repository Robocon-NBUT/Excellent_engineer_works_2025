# include <iostream>
using namespace std;

int main()
{
    int n;
cin >> n; // 读取序列长度

int
arr[1000]; // 定义数组存储序列
for (int i = 0; i < n; i++) {
    cin >> arr[i]; // 读取序列元素
}

// 冒泡排序核心逻辑
for (int i = 0; i < n - 1; i++) {
for (int j = 0; j < n - i - 1; j++) {
if (arr[j] > arr[j + 1]) {
// 交换元素
int temp = arr[j];
arr[j] = arr[j + 1];
arr[j + 1] = temp;
}
}
}

// 输出排序结果
for (int i = 0; i < n; i++) {
cout << arr[i];
if (i != n - 1) cout << " ";
}
cout << endl;

return 0;
}
