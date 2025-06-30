import random

numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]
with open("input.txt", "w", encoding="utf-8") as f:
    f.write(' '.join(str(num) for num in numbers))
print("写入 input.txt 的 unsigned int 数值为: " + ' '.join(str(num) for num in numbers))

with open("input.txt", "r", encoding="utf-8") as f:
    data = f.read()

numbers = data.split()
int_numbers = [int(x) for x in numbers]

s = 0
for i in int_numbers:
    s += i
ave = s / len(int_numbers)

print("平均值是：", f"{ave:.2f}")

with open("output.txt", "w", encoding="utf-8") as f:
    f.write("平均值是：" + f"{ave:.2f}\n")

print("写入成功")
