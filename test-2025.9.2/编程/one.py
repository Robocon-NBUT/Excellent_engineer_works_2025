n=int(input())
shuju=[int(x) for x in input().split()]
def sort(arr):
    length=len(arr)
    for i in range(length-1):#i是弄了多少次
        for j in range(length-1-i):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]

    return arr
sort_shuju=sort(shuju)
for i in sort_shuju:
    print(str(i),end=' ')


