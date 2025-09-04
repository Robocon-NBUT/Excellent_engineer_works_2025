num =int(input("输入序列长度"))
data=input().split()
while len(data) !=num:
    data = input().split()
data = [int(x) for x in data]
def paixu(num1):
    n =len(num1)
    for i in range(n):
        for j in range(0,n-i-1):
            if num1[j] > num1[j+1]:
                temp = num1[j]
                num1[j] = num1[j+1]
                num1[j+1] = temp
    return num1
data = paixu(data)
for i in data:
    print(i,end=" ")
