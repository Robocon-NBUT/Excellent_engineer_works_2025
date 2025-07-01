import random

# 生成五个随机数并写入 input.txt
random_numbers = [random.randint(1, 100) for _ in range(5)]
with open("input.txt", "w") as f:
    f.write(" ".join(map(str, random_numbers)))

# 打印在终端
print("生成的随机数:", " ".join(map(str, random_numbers)))

# 从 input.txt 读取数据并计算平均值
with open("input.txt", "r",encoding = "utf-8") as f:
    data = list(map(int, f.read().strip().split()))

# 计算平均值
mean = sum(data) / len(data)

# 将平均值写入 output.txt
with open("output.txt", "w",encoding = "utf-8") as f:
    f.write(f"平均值: {mean}\n")

# 打印平均值到终端
print(f"数据的数量：{len(data)}")
print(f"平均值: {mean}")

print("操作已完成")
