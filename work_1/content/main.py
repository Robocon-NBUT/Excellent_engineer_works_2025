import random
with open("input.txt","w") as file:
    n = 5
    while n > 0:
        x = random.randint(1,1001)
        print(x)
        file.write(f"{x} ")
        n = n - 1
with open("input.txt","r") as file :
    content = file.read()
    numbers = [int(num) for num in content.split() if num.strip()]
    with open("output.txt","w") as file :
        average = sum(numbers)/len(numbers)
        print(average)
        file.write(f"{average}")













