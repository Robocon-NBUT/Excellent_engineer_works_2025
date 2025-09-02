def bubble_sort(data):
   n=len(data)
   for i in range(n-1):
       for j in range(n-1-i):
           if data[j]>data[j+1]:
               temp=data[j+1]
               data[j+1]=data[j]
               data[j]=temp
   return data
n = int(input())
data = []
for i in range(1, n + 1):
    nums = list(map(int, input().split()))
    data.extend(nums)
sort_data= bubble_sort(data)
print(sort_data)





