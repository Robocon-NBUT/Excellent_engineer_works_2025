# 输入部分
n = int(input())
sequence = list(map(int, input().split()))

# 快速排序函数
def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)

# 排序
sorted_seq = quick_sort(sequence)

# 输出部分
print(' '.join(map(str, sorted_seq)))