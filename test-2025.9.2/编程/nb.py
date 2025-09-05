n = int(input())
fyj = list(map(int, input().split()))
for i in range(n - 1):
    for j in range(n - 1 - i):
        if fyj[j] > fyj[j + 1]:           
            fyj[j], fyj[j + 1] = fyj[j + 1], fyj[j]
print(' '.join(map(str, fyj)))