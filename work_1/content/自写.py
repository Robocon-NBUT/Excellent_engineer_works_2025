import random
nums=[random.randint (0,2**32-1)for _ in range(5)]
with open("input.txt","w")as f:
    f.write(" ".join(map(str,nums)))
    print(f"随机数:{' '.join(map(str,nums))}")
with open("output.txt","w")as f:
    data=list(map(int,nums))
    f.write(f"均值为{sum(data)/len(data)}\n")
    print(f"均值为{sum(data)/len(data)}\n")