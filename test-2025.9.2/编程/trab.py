n=int(input('请输入需要排列的数字的个数'))
nums=[None for _ in range(n)]
print('请输入需要排列的数字')
for i in range(n):
    nums[i]=int(input())
def partition(arr,start,end):
    tmp=arr[start]
    while start<end:
        while arr[end]>=tmp and start<end:
            end-=1
            arr[start]=arr[end]
            while arr[start]<=tmp and start<end:
                start+=1
        arr[end] = arr[start]
        arr[start]=tmp
        return start
def quick_sort(arr,start,end):
    if start < end:
       mid = partition(arr, start, end)
       quick_sort(arr,start,mid-1)
       quick_sort(arr,mid+1,end)
quick_sort(nums,0,len(nums)-1)
print("排序结果",nums)