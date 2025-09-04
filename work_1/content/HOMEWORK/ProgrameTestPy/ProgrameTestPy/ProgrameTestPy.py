import random
lr=[]
for i in range(5):
    lr.append(random.randint(0,100))
print("in:")
with open("C:\\Users\\36744\\Desktop\\newfile\\Excellent_engineer_Yaclum_works_2025\\work_1\\content\\HOMEWORK\\input.txt","w")as iput:
    for item in lr:
        iput.write(str(item)+' ')
        print(item,end=' ')
print()
with open("C:\\Users\\36744\\Desktop\\newfile\\Excellent_engineer_Yaclum_works_2025\\work_1\\content\\HOMEWORK\\input.txt","r")as iput:
    nums=iput.read().split()
j=0
sum=0
for i in nums:
    sum=sum+int(i)
    j=j+1
a=sum/j
print("out:")
print(a)
with open("C:\\Users\\36744\\Desktop\\newfile\\Excellent_engineer_Yaclum_works_2025\\work_1\\content\\HOMEWORK\\output.txt","w")as oput:
    oput.write(str(a))