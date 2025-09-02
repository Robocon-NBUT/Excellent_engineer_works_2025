import random
numbers=[]
pj=0
random_numbers=[random.randint(1,100) for i in range(5)]
with open('input.txt','w') as f1:
    for random_number in random_numbers:
        f1.write(str(random_number)+' ')
with open('input.txt','r') as f2:
    line=f2.readline()
    numbers=line.split()
    for number in numbers:
        pj+=int(number)
    pj/=len(numbers)
with open('output.txt','w') as f3:
    f3.write(str(pj))





