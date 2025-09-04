def quick_sort(arr):
    """快速排序函数，对列表进行升序排序"""
    # 递归终止条件：如果列表长度小于等于1，则已经有序
    if len(arr) <= 1:
        return arr

    # 选择中间元素作为基准
    pivot = arr[len(arr) // 2]

    # 划分成小于、等于和大于基准的三个子列表
    left = [x for x in arr if x < pivot]  # 所有小于基准的元素
    middle = [x for x in arr if x == pivot]  # 所有等于基准的元素
    right = [x for x in arr if x > pivot]  # 所有大于基准的元素

    # 递归排序左右子列表，并合并结果
    return quick_sort(left) + middle + quick_sort(right)


def main():
    # 读取输入
    n = int(input())  # 读取序列长度
    sequence = list(map(int, input().split()))  # 读取序列元素并转换为整数列表

    # 验证输入长度
    if len(sequence) != n:
        print("输入的序列长度与n不匹配")
        return

    # 调用快速排序
    sorted_sequence = quick_sort(sequence)

    # 输出排序结果，元素之间用空格分隔
    print(' '.join(map(str, sorted_sequence)))


# 程序入口
if __name__ == "__main__":
    main()
