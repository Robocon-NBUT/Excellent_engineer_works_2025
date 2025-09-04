import random
import statistics


random_numbers = [random.randint(0, 999) for _ in range(5)]


with open("input.txt", "w") as f:
    f.write(" ".join(map(str, random_numbers)))


mean_value = statistics.mean(random_numbers)
variance_value = statistics.variance(random_numbers)


with open("output.txt", "w") as f:
    f.write(f"均值：{mean_value:.2f}\n")
    f.write(f"方差：{variance_value:.2f}\n")


print(f"随机数已写入input.txt")
print(f"计算结果已保存至output.txt")
print(f"均值：{mean_value:.2f} | 方差：{variance_value:.2f}")