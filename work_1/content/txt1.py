import random
with open("input.txt","w",encoding="UTF-8") as fr1:
    for i in range(1,6):
        mun=random.randint(1,10)
        fr1.write(f"{mun} ")

with open("input.txt","r",encoding="UTF-8") as fr:
    data=[]
    for line in fr:
        line=line.strip()
        if line:
            number=[int(part)for part in line.split()]
            data.extend(number)
total=sum(data)
count=len(data)
average=total/count
with open("output.txt","w",encoding="UTF-8") as fw:
    fw.write(f"{average:.2}")
print(average)












