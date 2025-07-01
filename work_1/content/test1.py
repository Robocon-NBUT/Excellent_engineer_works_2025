import requests
import numpy as np
import random
#写入数据
def writefile(list,filename):
    with open(filename,'a') as file:
        for num in list:
            file.write(str(num)+' ')
    file.close()
#读取数据
def readfile(filename):
    with open(filename,'r') as file:
        line = file.readline().strip()
    list=[int(num) for num in line.split()]#列表推导式
    file.close()
    return list

data=[]
input_filename=r"C:\Users\17989\Desktop\Python读取文件中的整形数据求平均写入新文件\input.txt"
output_filename=r"C:\Users\17989\Desktop\Python读取文件中的整形数据求平均写入新文件\output.txt"
#随机生成
for i in range(5):
    num=random.randint(0,100)
    data.append(num)
writefile(data,input_filename)
#读取
arr=readfile(input_filename)
for num in arr:
    print(num,end=' ')
print('\n')
average=np.mean(arr)#求平均值
#写入平均值
with open(output_filename,'a') as file:
    file.write(f"平均数：{average}")
print(average)


