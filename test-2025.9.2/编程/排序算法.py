def solve():
    n = int(input())
    if n <= 0:
        return
    num = list(map(int, input().split()))
    num = sorted(num)
    for i in range(n):
        print(num[i], end=" ")


solve()
