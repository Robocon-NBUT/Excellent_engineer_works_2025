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
      print("д���ļ�ʱ����{e}")

try:
        with open('input.txt', 'r') as f:
            line = f.readline()
            data0 = [float(num4) for num4 in line.strip().split()]
        aaa = pjs(data0)
        with open('output.txt', 'w') as f:
            f.write(f"ƽ������{aaa:.2f}\n")
      
except IOError as e:
        print(f"��ȡ��д���ļ�ʱ����{e}")
try:
        print("\ninput.txt �ļ����ݣ�")
        with open('input.txt', 'r',) as f:
            content = f.read()
            print(content if content else "(�ļ�Ϊ��)")
except IOError as e:
        print(f"�޷���ȡ1.txt��{e}")
try:
        print("\noutput.txt �ļ����ݣ�")
        with open('output.txt', 'r') as f:
            content = f.read()
            print(content if content else "(�ļ�Ϊ��)")
except IOError as e:
        print(f"�޷���ȡoutput.txt��{e}")