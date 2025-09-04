import random
random_nums = [random.randint(0, 2**32 - 1) for _ in range(5)]
with open('input.txt', 'w') as f:
    num_str = ' '.join(map(str, random_nums))
    f.write(num_str)
    print(num_str)
with open('input.txt', 'r') as f:
    nums = list(map(int, f.read().split()))
    average = sum(nums) / len(nums)
with open('output.txt', 'w') as f:
    f.write(str(average))
    print(average)