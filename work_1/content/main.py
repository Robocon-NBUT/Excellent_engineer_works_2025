import random

with open("input.txt","w") as ifs:
    num_str=""
    for _ in range(5):
        num = random.getrandbits(32)
        num_str+=str(num)+" "
    num_str=num_str.strip()
    ifs.write(num_str)
    print(num_str)
ifs.close()
print("已填入随机数")
num_sum=0
num_mid=0
with open("input.txt","r") as ofs:
    fnum_str=ofs.readline()
    for fnum in fnum_str.split():
        num = int(fnum)
        num_sum += num
ofs.close()
num_mid=float(num_sum/5.0)
print(f"平均数为：{num_mid} ")
with open("output.txt","w") as f:
    f.write(f"平均数为：{num_mid}")
f.close()
print("已填入平均数")