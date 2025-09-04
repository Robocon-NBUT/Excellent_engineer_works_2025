def bubbleSort(arr,n):
    for i in range(n):
        for j in range(n-i-1):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
    return arr

n=int(input().strip())
nums=list(map(int,input().split()))
sort_nums=bubbleSort(nums,n)
for i in range(len(sort_nums)):
    if i!=0:
        print(" ",end="")
    print(sort_nums[i],end="")
print()

