import random
import time
def QuickSort(arr,start,end):  #快排
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

def BubbleSort(arr):          #冒泡排序
    n=len(arr)
    for i in range(n):
        flag=False       #外层优化
        temp=len(arr)-1  #内层优化
        for j in range(0,temp):
            if arr[j]>arr[j+1]:
                arr[j],arr[j+1]=arr[j+1],arr[j]
                flag=True
                temp=j
        if not flag:
            break
def CountSort(arr):           #桶计数
    max_value=1000
    res=[]
    count_nums = [0 for i in range(max_value + 1)]
    for num in arr:
        count_nums[num] += 1
    for i in range(len(count_nums)):
        if count_nums[i] != 0:
            res.extend(count_nums[i] * [i])
    return res

def MergeSort(arr):         #归并排序
    if len(arr)<=1:
        return arr
    num=int(len(arr)/2)
    left=MergeSort(arr[:num])
    right=MergeSort(arr[num:])
    return Merge(left, right)
def Merge(left,right):
    r, l=0, 0
    res=[]
    while l<len(left) and r<len(right):
        if left[l] <= right[r]:
            res.append(left[l])
            l+=1
        else:
            res.append(right[r])
            r += 1
    res+=list(left[l:])
    res+=list(right[r:])
    return res

n=int(input("请输入排序个数"))
arr=[0]*n
arr1=[0]*n
arr2=[0]*n
for i in range(0,n):
    t=random.randint(0,1000)
    arr[i]=t
    arr1[i]=t
    arr2[i]=t

start_time=time.time()
arr_end=n-1
QuickSort(arr,0,arr_end)
end_time=time.time()
quick_sort_time=end_time-start_time
print(arr)
print("快速排序用时:",quick_sort_time)

start_time1=time.time()
BubbleSort(arr1)
end_time1=time.time()
bubble_sort_time=end_time1-start_time1
print(arr1)
print("冒泡排序用时:",bubble_sort_time)

start_time2=time.time()
res=CountSort(arr2)
end_time2=time.time()
count_sort_time=end_time2-start_time2
print(res)
print("桶（计数）排序用时:",count_sort_time)
start_time3=time.time()
res1=MergeSort(arr2)
end_time3=time.time()
merge_sort_time=end_time3-start_time3
print(res1)
print("归并排序用时:",merge_sort_time)