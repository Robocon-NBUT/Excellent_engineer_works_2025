def dz(n,a):
    a=list(map(int, a.split()))
    for i in range(n):
      for j in range(0,n-i-1):
        if a[j]<a[j+1]:
          temp=a[j]
          a[j]=a[j+1]
          a[j+1]=temp
    return a
n = int(input("请输入序列长度:"))
data = input("输入序列:")
data1=dz(n, data)
print("排序后的序列:"," ".join(map(str,data1)))
