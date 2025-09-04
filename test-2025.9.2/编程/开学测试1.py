n = int(input())
arr = list(map(int, input().split()))
def bubble_sort(arr):
    length = len(arr)
    for i in range(length - 1):
        for j in range(length - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr

sorted_arr = bubble_sort(arr)
print(" ".join(map(str, sorted_arr)))