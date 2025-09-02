def swap(arr,a,b):
    arr[b],arr[a]=arr[a],arr[b]
def partition(arr,left,right):
    pivot=left
    index=pivot+1
    i=index
    while i<=right:
        if arr[i]<arr[pivot]:
            swap(arr,i,index)
            index+=1
        i+=1
    swap(arr,pivot,index-1)
    return index-1
def quicksort(arr,left=None,right=None):
    left=0 if not isinstance(left,int) else left
    right=len(arr)-1 if not isinstance(right,int) else right
    if left<right:
        partitionindex=partition(arr,left,right)
        quicksort(arr,left,partitionindex-1)
        quicksort(arr,partitionindex+1,right)
        return arr

n = input()
arr = list(map(int, input().split()))
sorted_arr = quicksort(arr)
print(' '.join(map(str, sorted_arr)))

