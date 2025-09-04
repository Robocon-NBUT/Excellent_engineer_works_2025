n=int(input('输入序列长度：'))
data=input()
data=data.split(' ')
for i in range(n):
    for j in range(0，n-i-1):
        if data[j]>data[j+1]:
            data[j],data[j+1]=data[j+1],data[j]
for i in range(n):
    print(data[i]+' ',end=' ')