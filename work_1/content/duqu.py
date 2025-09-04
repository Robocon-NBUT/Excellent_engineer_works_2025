import random
random_numbers=[str(random.randint(0,9))for _ in range(5)]
with open(file=r"input.txt",mode="w",encoding="utf-8")as f:
    f.write(' '.join(random_numbers))
print(' '.join(random_numbers))
total=0
for num in random_numbers:
    total+=int(num)
average=total/len(random_numbers)
with open("output.txt","w",encoding="utf-8")as f:
    f.write(f"{average:.2f}")
print(average)