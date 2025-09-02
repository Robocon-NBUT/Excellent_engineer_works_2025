# 读入数据
n = int(input().strip())          # 第一行：序列长度
nums = list(map(int, input().split()))  # 第二行：空格分隔的整数序列

# 冒泡排序（升序）
for i in range(n - 1):
    for j in range(n - 1 - i):
        if nums[j] > nums[j + 1]:
            nums[j], nums[j + 1] = nums[j + 1], nums[j]

# 按要求输出，元素之间用空格分隔
print(' '.join(map(str, nums)))