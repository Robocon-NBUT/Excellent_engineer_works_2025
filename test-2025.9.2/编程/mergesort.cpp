using namespace std;
#include <vector>
#include <iostream>


void MergeSort(int *shuzu, int left, int right,int*temp)
{
    if (left == right)
    {
        return;
    }
    int middle = (left + right) / 2;
    MergeSort(shuzu, left, middle,temp);
    MergeSort(shuzu, middle + 1, right,temp);
    int p1 = left;
    int p2 = middle + 1;
    while ((p1 <= middle) && (p2 <= right))
    {
        if (shuzu[p1] < shuzu[p2])
        {
            temp[p1 - left + p2 - middle - 1] = shuzu[p1];
            p1++;
        }
        else
        {
            temp[p1 - left + p2 - middle - 1] = shuzu[p2];
            p2++;
        }
    }
    while (p2 <= right)
    {
        temp[p2 - left] = shuzu[p2];
        p2++;
    }
    while (p1 <= middle)
    {
        temp[p1 - left + right - middle] = shuzu[p1];
        p1++;
    }
    for (int i = left; i <= right; i++)
    {
        shuzu[i] = temp[i - left];
    }
    return;
}

int main()
{
    int number;
    cin >> number;
    int* shuzu = new int[number];
    int* temp = new int[number];
    for(int i = 0;i<number;i++)
    {
        cin >> shuzu[i];
    }
    MergeSort(shuzu,0,number-1,temp);
    for(int i = 0;i < number;i++)
    {
        cout << shuzu[i];
        if(i != number-1)
        {
            cout << " ";
        }
    }
}