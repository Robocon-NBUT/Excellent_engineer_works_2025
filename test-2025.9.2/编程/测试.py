n=int(input())
num=input()
num=num.split(' ')
def bubble(nums):
    for i in range(0,len(nums)-1):
        for j in range(0,len(nums)-1-i):
            if num[j]>nums[j+1]:
                nums[j],nums[j+1]=nums[j+1],nums[j]
    return nums
print(bubble(num))
