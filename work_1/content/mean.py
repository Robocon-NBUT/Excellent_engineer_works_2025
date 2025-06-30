import random

def calculate_mean(data):
    if not data: 
        return 0
    return sum(data) / len(data)

nums = [random.randint(0, 2**32 - 1) for _ in range(5)]

print("数据为:")

with open('input.txt', 'w') as f:
    print(*nums, sep=' ', end='\n')
    f.write('\n'.join(map(str, nums)) + '\n')  

with open('input.txt', 'r') as f:
    data = [int(line.strip()) for line in f if line.strip()]  

mean = calculate_mean(data)

print(f"数据均值: {mean:.4f}")

with open('output.txt', 'w') as f:
    f.write(f"数据均值: {mean:.4f}\n")