def quick_sort(arr, left, right):
    if left >= right:
        return
    i, j = left, right
    pivot = arr[left]
    while i < j:
        while i < j and arr[j] >= pivot:
            j -= 1
        if i < j:
            arr[i] = arr[j]
            i += 1
        while i < j and arr[i] <= pivot:
            i += 1
        if i < j:
            arr[j] = arr[i]
            j -= 1
    arr[i] = pivot
    quick_sort(arr, left, i - 1)
    quick_sort(arr, i + 1, right)

n = int(input())
a = list(map(int, input().split()))

quick_sort(a, 0, n - 1)

for i in range(n):
    print(a[i], end=" ")
