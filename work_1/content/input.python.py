#-*-coding:gbk-*-
import random
def pjs(data):
  n=len(data)
  if n==0:
    return 0
  num1=sum(data)
  return num1/n
def display(filename):
    try:
        with open(filename,'r')as f:
            print(f"�ļ�{filename}���ݣ�")
            print(f.read())
    except IoError:
        print(f"�޷����ļ�{filename}")
def setdata():
    data=[]
    num2=0
    while num2<5:
        num3=random.randint(1,100)
        data.append(num3)
        num2+=1
    return data
data=setdata()
try:
    with open("input.txt",'w')as f:
        for num in data:
            f.write(f"{num}\n")
except IoError as e:
    print(f"д�����{e}")
try:
    with open('input.txt','r')as f:
        line=f.readline()
        data0=[float(num3) for num3 in line.strip().split()]
        aaa=pjs(data0)
    with open('output.txt','w')as f:
        f.write(f"ƽ������{aaa}\n")
except IoError as e:
    print(f"��ȡ��д�����{e}")
display("input.txt")
display("output.txt")


