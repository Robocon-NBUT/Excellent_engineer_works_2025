n = int(input())
nums = list(map(int, input().split()))
for i in range(n - 1):
    for j in range(n - 1 - i):
        if nums[j] > nums[j + 1]:
            nums[j], nums[j + 1] = nums[j + 1], nums[j]
print(' '.join(map(str, nums)))