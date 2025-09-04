def px(n, a):
    a = list(map(int, a.split()))
    for i in range(n):
        for j in range(0, n-i-1):
            if a[j] > a[j+1]:
                b = a[j]
                a[j] = a[j+1]
                a[j+1] = b
    return a
n = int(input("输入序列长度:"))
xl = input("输入序列:")
sxxl = px(n, xl)

print("结果序列:", " ".join(map(str, sxxl)))
