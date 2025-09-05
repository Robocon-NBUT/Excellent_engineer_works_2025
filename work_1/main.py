import random

random_numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]

with open('input.txt', 'w') as f:
     f.write(' '.join(map(str, random_numbers)))
print("生成随机数字：",' '.join(map(str, random_numbers)))

with open('input.txt', 'r') as f:
    numbers = list(map(int, f.read().split()))
    average = sum(numbers) / len(numbers)

with open('output.txt', 'w') as f:
    f.write(str(average))
print("计算的平均数：", average)