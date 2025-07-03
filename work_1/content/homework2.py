import random
import struct

# 生成五个随机的32位无符号整数
random_numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]

# 将随机数以空格隔开写入input.txt
with open('input.txt', 'w') as f:
    f.write(' '.join(map(str, random_numbers)))

# 在终端打印生成的随机数
print("生成的随机数:", ' '.join(map(str, random_numbers)))

# 从input.txt中读取数据
with open('input.txt', 'r') as f:
    data = f.read()
    numbers = list(map(int, data.split()))

# 计算均值（float32）
mean = float(sum(numbers)) / len(numbers)
mean_float32 = struct.unpack('f', struct.pack('f', mean))[0]  # 确保是float32精度

# 将均值写入output.txt
with open('output.txt', 'w') as f:
    f.write(str(mean_float32))

# 在终端打印均值
print("计算得到的均值:", mean_float32)