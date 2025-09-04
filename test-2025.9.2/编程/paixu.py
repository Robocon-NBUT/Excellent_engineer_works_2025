n = int(input())  # 读取序列长度

# 读取一行输入，分割成多个字符串，再转换为整数列表
arr = list(map(int, input().split()))

# 冒泡排序核心逻辑
for i in range(n - 1):
    for j in range(n - i - 1):
        if arr[j] > arr[j + 1]:
            # 交换元素
            arr[j], arr[j + 1] = arr[j + 1], arr[j]

# 输出排序结果
for i in range(n):
    print(arr[i], end="")
    if i != n - 1:
        print(" ", end="")
print()