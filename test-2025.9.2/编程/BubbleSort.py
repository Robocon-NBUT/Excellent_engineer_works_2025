def BubbleSort(nums):
    n = len(nums)
    for i in range(n):
        flag = False
        for j in range(0,n-i-1):
            if nums[j] > nums[j+1]:
                flag = True
                nums[j] ,nums[j+1] = nums[j+1], nums[j]
        if not flag:
            break
size = int(input())
numbers = list(map(int, input().split()))
BubbleSort(numbers)
for i in range(size):
    print(str(numbers[i]),end = ' ')