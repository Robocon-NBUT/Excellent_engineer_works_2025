import random

with open("input.txt", "w") as inputFile:
    numbers = [random.randint(0, 99) for _ in range(5)]  # 生成0到99之间的五个随机整数
    inputFile.write(" ".join(map(str, numbers)))  # 将数字用空格隔开写入文件

with open("input.txt", "r") as inputFile:
    numbers = list(map(int, inputFile.read().split()))  # 读取文件内容并转换为整数列表
    average = sum(numbers) / len(numbers)  # 计算均值

with open("output.txt", "w") as outputFile:
    outputFile.write(f"平均值为：{average:.2f}\n")

print("随机数已写入 input.txt，平均值已写入 output.txt。")