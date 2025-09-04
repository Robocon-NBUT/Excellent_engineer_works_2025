import random

number=[random.randint(0,100) for i in range(5)]
with open('input.txt', 'w') as f:
    f.write(' '.join(map(str, number)))
with open('input.txt') as f:
    nums = [int(num) for num in f.read().split()] 

mean = sum(nums) / len(nums)  

with open('output.txt', 'w') as f:
    f.write(f"数据个数: {len(nums)}\n") 
    f.write(f"平均值: {mean:.2f}\n")   

print("计算完成，结果已保存到 output.txt")
