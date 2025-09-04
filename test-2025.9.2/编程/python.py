def selection_sort(arr):
    """
    选择排序函数
    """
    n = len(arr)
    # 外层循环，控制排序的轮数
    for i in range(n):
        # 假设当前轮次的第一个元素是最小的
        min_index = i
        # 内层循环，在未排序部分寻找最小元素
        for j in range(i + 1, n):
            if arr[j] < arr[min_index]:
                min_index = j
        # 将找到的最小元素与当前位置交换
        arr[i], arr[min_index] = arr[min_index], arr[i]
    return arr

def main():
    """
    主函数，处理输入输出
    """
    # 读取第一行：序列长度
    n = int(input().strip())
    # 读取第二行：序列元素，以空格分隔
    arr = list(map(int, input().split()))
    
    # 使用选择排序进行升序排序
    sorted_arr = selection_sort(arr)
    
    # 输出排序结果，以空格分隔
    print(" ".join(map(str, sorted_arr)))

# 调用主函数
if __name__ == "__main__":
    main()
