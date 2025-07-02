import random
import numpy as np
random_nums = [random.randint(0, 4294967295) for _ in range(5)]

print(" ".join(map(str, random_nums)))

with open("input.txt", "w") as f:
    f.write(" ".join(map(str, random_nums)))

def cal_mean(data):
    return np.float32(sum(data) / len(data))

def cal_variance(data,mean):
    squared_diff = [(mean-x)**2 for x in data]
    return sum(squared_diff) / len(data)

with open('input.txt','r') as f:
    data = []
    for line in f:
        numbers = [int(num)for num in line.strip().split()]
        data.extend(numbers)

mean = cal_mean(data)
variance = cal_variance(data,mean)

print(f"数据数量：{len(data)}")
print(f"均值：{mean:.2f}")
print(f"方差：{variance:.2f}")

with open('output.txt','w') as f:
    f.write(f"数据数量：{len(data)}\n")
    f.write(f"均值：{mean:.2f}\n")
    f.write(f"方差：{variance:.2f}\n")
