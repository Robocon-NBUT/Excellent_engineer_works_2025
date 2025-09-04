import random

num = []
for i in range(5):
    num.append(random.randint(0, 2**32 - 1))
input_file = open('input.txt', 'w')
for n in num:
    input_file.write(str(n) + ' ')
input_file.close()
for n in range(len(num)):
    print(num[n], end=" ")
print()
average = 0
input_file = open('input.txt', 'r')
numbers = input_file.read().split()
for number in numbers:
    average += int(number)
input_file.close()
average /= len(numbers)
output_file = open('output.txt', 'w')
output_file.write(str(average))
output_file.close()
print(average)



