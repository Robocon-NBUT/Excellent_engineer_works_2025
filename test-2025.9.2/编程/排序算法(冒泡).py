def bubble_sort(arr):
    n = len(arr)
    for i in range (n - 1):
        for j in range(n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
n = int(input())
numbers = list(map(int, input().split()))
sorted_numbers = bubble_sort(numbers)
print(sorted_numbers)
