import random

# 1. 生成5个随机数
nums = [random.randint(0, 4294967295) for _ in range(5)]

# 2. 写入文件并打印
s = ' '.join(map(str, nums))
print(s)
with open('input.txt', 'w') as f:
    f.write(s)

# 3. 读取并计算均值
with open('input.txt') as f:
    data = list(map(int, f.read().split()))
    avg = sum(data)/len(data)

# 4. 输出结果
with open('output.txt', 'w') as f:
    f.write(str(avg))
print(avg)
