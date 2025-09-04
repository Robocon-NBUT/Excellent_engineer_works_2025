def quick_sort(arr):
    """快速排序函数（递归实现）"""
    if len(arr) <= 1:
        return arr
    # 选择基准值，使用数组中间元素
    pivot = arr[len(arr) // 2]
    # 分支语句：按与基准值的大小关系分区
    left = [x for x in arr if x < pivot]   # 小于基准值的元素
    middle = [x for x in arr if x == pivot]# 等于基准值的元素
    right = [x for x in arr if x > pivot]  # 大于基准值的元素
    # 递归排序左右分区并合并结果
    return quick_sort(left) + middle + quick_sort(right)

# 输入功能（10分）
n = int(input())  # 读取序列长度
sequence = list(map(int, input().split()))  # 读取序列元素

# 执行排序
sorted_sequence = quick_sort(sequence)

# 输出功能（10分）
print(' '.join(map(str, sorted_sequence)))
