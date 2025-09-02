import random
def QuickSort(arr,start,end):
    if start>=end:
        return
    mid=arr[start]
    left=start
    right=end
    while left!=right:
        while left!=right and arr[right]>=mid:
            right-=1
        arr[left]=arr[right]
        while left!=right  and arr[left]<mid:
            left+=1
        arr[right]=arr[left]
    arr[left]=mid
    QuickSort(arr,start,left-1)
    QuickSort(arr,left+1,end)
arr=[0]*100
for i in range(0,100):
    arr[i]=random.randint(0,100)
arr_end=len(arr)-1
QuickSort(arr,0,arr_end)
print(arr)