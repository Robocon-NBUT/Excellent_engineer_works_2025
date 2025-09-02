n = int(input())
arr = []
for i in range(n):
    row = list(map(int, input().split()))
    arr.append(row)

flag = True
while flag:
    flag = False
    for i in range(n):
        for j in range(n):
            if arr[i][j] == 0:




# 输出结果
for i in range(n):
    for j in range(n):
        print(arr[i][j], end=" ")

