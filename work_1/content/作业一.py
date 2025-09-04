import random
import struct

# 生成5个32位无符号整数
random_numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]
print("生成的随机数:", random_numbers)

# 写入input.txt
with open("input.txt", "w") as f:
    f.write(' '.join(map(str, random_numbers)))

# 从input.txt读取
with open("input.txt", "r") as f:
    content = f.read().strip()

# 转换为数字列表
my_list = list(map(int, content.split()))

# 计算平均数（float32）
average = sum(my_list) / len(my_list)

# 写入output.txt（二进制格式）
with open("output.txt", "wb") as f:
    f.write(struct.pack('!f', average))

print(f"这些数的平均数为：{average}")
print("结果已经写入output.txt")