<<<<<<< HEAD
import random
input_file = "input.txt"
output_file = "output.txt"
random_numbers = [random.randint(1, 100) for _ in range(5)]
with open(input_file, 'w') as f:
    f.write(' '.join(map(str, random_numbers)))
    print(f"已生成随机数: {random_numbers}，并写入 {input_file}")
average = sum(random_numbers) / len(random_numbers) if random_numbers else 0
with open(output_file, 'w') as f:
    f.write(f"{average:.2f}")
    print(f"平均值 {average:.2f} 已写入 {output_file}")
    
=======
import random
input_file = "input.txt"
output_file = "output.txt"
random_numbers = [random.randint(1, 100) for _ in range(5)]
with open(input_file, 'w') as f:
    f.write(' '.join(map(str, random_numbers)))
    print(f"已生成随机数: {random_numbers}，并写入 {input_file}")
average = sum(random_numbers) / len(random_numbers) if random_numbers else 0
with open(output_file, 'w') as f:
    f.write(f"{average:.2f}")
    print(f"平均值 {average:.2f} 已写入 {output_file}")
    
>>>>>>> 2c954f6880ad6a8f8e799df95b32c6ef497e2c3a
