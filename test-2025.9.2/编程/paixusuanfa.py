import random
n=random.randint(0,9)
random_numbers=[str(random.randint(0,9))for _ in range(n)]
text_content=f"{n}\n{' '.join(random_numbers)}"
print(text_content)

#放入输入的文件中
with open(file="text.txt",mode="w",encoding="utf-8")as f:
    f.write(text_content)

for i in range(len(random_numbers)-1):
    for j in range(len(random_numbers)-1-i):
        if random_numbers[j]>random_numbers[j+1]:
            random_numbers[j],random_numbers[j+1]=random_numbers[j+1],random_numbers[j]
output_content=f"{n}\n{' '.join(map(str,random_numbers))}"
print(f"{output_content}")

with open(file="textout.txt",mode="w",encoding="utf-8")as f:
    f.write(f"{output_content}")