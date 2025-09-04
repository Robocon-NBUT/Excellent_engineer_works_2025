n = int(input())
nums = list(map(int, input().split()))
for i in range(n):
   for j in range(n-i-1):
       if nums[j] > nums[j+1]:
         nums[j], nums[j+1] = nums[j+1], nums[j]
print(' '.join(map(str, nums)))