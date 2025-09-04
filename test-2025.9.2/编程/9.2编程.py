n = int(input())
sequence = list(map(int, input().split()))

# 确保输入的序列长度与n一致
if len(sequence) != n:
    print(f"输入错误：序列长度应为{n}，实际为{len(sequence)}")
else:
    # 冒泡排序算法实现
    for i in range(n-1):
        # 每轮循环减少一次比较，因为最大的元素已经到位
        for j in range(n-1-i):
            # 如果当前元素大于下一个元素，则交换它们
            if sequence[j] > sequence[j+1]:
                sequence[j], sequence[j+1] = sequence[j+1], sequence[j]
    
    # 输出排序后的结果
    print(' '.join(map(str, sequence)))
