#include<iostream>
#include<vector>
using namespace std;

/*作用交换两个整数*/
void swap(int& a, int& b) {//swap交换两个整数的值，&表示引用传递
	int temp =a;
	a = b;
	b = temp;
}
/*划分函数，快速排序*/
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // 选择最右边的元素作为基准
    int i = (low - 1);      // 小于基准的元素的索引

    // 循环遍历数组，将小于基准的元素放到左边
    for (int j = low; j <= high - 1; j++) {
        // 分支语句：如果当前元素小于或等于基准
        if (arr[j] <= pivot) {
            i++;  // 增加小于基准区域的索引
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// 快速排序函数
void quickSort(vector<int>& arr, int low, int high) {
    // 分支语句：递归终止条件
    if (low < high) {
        // pi是划分后的基准元素索引
        int pi = partition(arr, low, high);

        // 递归排序基准元素左右两边的子数组
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    // 实现输入功能
    cin >> n;  // 读取序列长度

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 读取序列元素
    }

    // 调用快速排序函数
    quickSort(arr, 0, n - 1);

    // 实现输出功能
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if (i != n - 1) {
            cout << " ";  // 元素之间用空格分隔
        }
    }
    cout << endl;

    return 0;
}