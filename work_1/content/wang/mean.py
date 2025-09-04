import random

random_numbers=[]
for i in range(5):
    random_numbers.append(random.randint(0, 100))

# 写入input.txt文件
f=open('input.txt', 'w')
for i in range(len(random_numbers)):
    f.write(str(random_numbers[i]))
    if i<len(random_numbers) - 1:
        f.write(' ')
f.close()


for i in range(len(random_numbers)):
    print(random_numbers[i], end='')
    print(' ',end='')
print()

f=open('input.txt','r')
data=f.read().strip()
f.close()
numbers=[]
current_number=''
for char in data:
    if char==' ':
        numbers.append(int(current_number))
        current_number=''
    else:
        current_number+=char
if current_number!='':
    numbers.append(int(current_number))
sum_numbers=0
count=0
for num in numbers:
    sum_numbers+=num
    count+=1
average=sum_numbers/count

f = open('output.txt', 'w')
f.write(str(average))
f.close()

print(average)