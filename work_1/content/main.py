import random

# 生成5个无符号32位随机整数并写入文件
numbers = [random.randint(0, 2**32-1) for _ in range(5)]
print("生成的随机数:", " ".join(map(str, numbers)))

with open("input.txt", "w") as f:
    f.write(" ".join(map(str, numbers)))

# 从文件读取数据并计算平均值
with open("input.txt", "r") as f:
    data = f.read()
    numbers = list(map(int, data.split()))
    average = sum(numbers) / len(numbers)

# 将平均值写入输出文件
with open("output.txt", "w") as f:
    f.write(str(average))

print("计算的平均值:", average)
