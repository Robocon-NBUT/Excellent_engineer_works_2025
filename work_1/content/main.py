import random
INT32_MIN = -2**31
INT32_MAX = 2**31 - 1
numbers = [ ]
for i in range(5):
    numbers.append(random.randint(INT32_MIN,INT32_MAX))
print("生成的随机数:", " ".join(map(str, numbers)))
with open("input.txt", "w") as f:
    f.write(" ".join(map(str, numbers)))
with open("input.txt", "r") as f:
    read= list(map(int, f.read().split()))
average = sum(read) / len(read)
with open("output.txt", "w") as f:
    f.write(f"{average:.2f}")
print("计算的平均值:", f"{average:.2f}")