#include <stdio.h>
int main() 
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
	{
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++) 
	{
        int w = i;
        for (int j = i + 1; j < n; j++) 
		{
            if (arr[j] < arr[w]) 
			{
                w = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[w];
        arr[w] = temp;
    }
    for (int i = 0; i < n; i++) 
	{
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}



