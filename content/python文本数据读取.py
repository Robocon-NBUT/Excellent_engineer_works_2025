# -*- coding: gbk -*-
import random
def pjs(data):
   
    return sum(data)/len(data)

def setdata():
    data = []
    num2=0
    while num2<5:
        num3=random.randint(1,1000)
        data.append(num3)
        num2+=1
    return data

data = setdata()


try:
    with open('input.txt', 'w') as f:
     for num in data:
       f.write(f"{num} ")
except IOError as e:
      print("写入文件时出错：{e}")

try:
        with open('input.txt', 'r') as f:
            line = f.readline()
            data0 = [float(num4) for num4 in line.strip().split()]
        aaa = pjs(data0)
        with open('output.txt', 'w') as f:
            f.write(f"平均数：{aaa:.2f}\n")
      
except IOError as e:
        print(f"读取或写入文件时出错：{e}")
try:
        print("\ninput.txt 文件内容：")
        with open('input.txt', 'r',) as f:
            content = f.read()
            print(content if content else "(文件为空)")
except IOError as e:
        print(f"无法读取1.txt：{e}")
try:
        print("\noutput.txt 文件内容：")
        with open('output.txt', 'r') as f:
            content = f.read()
            print(content if content else "(文件为空)")
except IOError as e:
        print(f"无法读取output.txt：{e}")