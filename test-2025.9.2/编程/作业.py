n = int(input())
w = list(map(int, input().split()))
for i in range(n - 1):
    for j in range(0, n - i - 1):
        if w[j] > w[j + 1]:
            w[j], w[j + 1] = w[j + 1], w[j]
print(" ".join(map(str, w)))