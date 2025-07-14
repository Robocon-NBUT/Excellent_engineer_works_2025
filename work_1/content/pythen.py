import random
random_numbers = [random.randint(0, 2**32 - 1) for _ in range(5)]
line = ' '.join(map(str, random_numbers))
print(line)
with open('input.txt', 'w') as f:
    f.write(line + '\n')
with open('input.txt', 'r') as f:
    input_line = f.readline().strip()
data = list(map(int, input_line.split()))
sum_values = sum(data)
mean_value = float(sum_values) / len(data) 
print("{0:.7g}".format(mean_value))
with open('output.txt', 'w') as f:
    f.write("{0:.7g}\n".format(mean_value))    