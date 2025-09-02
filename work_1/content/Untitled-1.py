import random
import os

def getrnums():
    with open("input.txt", "w") as f:
        numbers = []
        for _ in range(5):
            rnum = random.randint(0, 0x7FFFF)  
            numbers.append(rnum)
            f.write(f"{rnum} ")
        f.seek(f.tell() - 1)  
        f.truncate()
    return numbers

def getavg():
    if not os.path.exists("input.txt"):
        print("错误：输入文件 input.txt 未找到！")
        return None

    with open("input.txt", "r") as f:
        line = f.readline()
        nums = []
        for num_str in line.split():
            nums.append(int(num_str))

    if not nums:
        print("文件中没有有效的数字数据")
        return None

    sum = 0
    for num in nums:
        sum += num
    avg = sum / len(nums)

    with open("output.txt", "w", encoding="utf-8") as f:
        f.write(f"平均数：{avg:.6f}\n")
    print(f"平均数：{avg:.6f}")
    print("计算完成！结果已保存到 output.txt")
    return avg

try:
    numbers = getrnums()
    print("生成的随机数：", " ".join(map(str, numbers)))
    getavg()
except Exception as e:
    print(f"发生错误：{e}")