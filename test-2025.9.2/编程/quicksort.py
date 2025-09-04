def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    n= arr[len(arr) // 2]
    left = [x for x in arr if x < n]
    middle = [x for x in arr if x == n]
    right = [x for x in arr if x > n]
    return quick_sort(left) + middle + quick_sort(right)

n = int(input())
arr = list(map(int, input().split()))
sort = quick_sort(arr)
print(" ".join(map(str, sort)))