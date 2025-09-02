#include <iostream>
#include <vector>
using namespace std;

void bubble_sort(vector<int>& arr, int len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
              
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int len;
    cin >> len;
    vector<int> arr(len);

    for (int i = 0; i < len; i++) {
        cin >> arr[i];
    }

 
    bubble_sort(arr, len);

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

