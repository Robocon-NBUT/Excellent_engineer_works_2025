def bubble_sort(arr):
    n = len(arr)
    for i in range(n-1):
        for j in range(0,n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

if __name__ == '__main__':
    n = int(input())
    arr = list(map(int, input().split()))
    sorted_arr = bubble_sort(arr)
    for num in arr:
        print(num,end=' ')