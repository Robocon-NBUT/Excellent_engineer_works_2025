def print_arr(arr, n):
    for i in range(n):
        print(arr[i], end=' ')
    print()

def qsort(arr, l, r):
    i, j = l, r
    mid = arr[(l + r) // 2]
    while True:
        while arr[i] < mid:
            i += 1
        while arr[j] > mid:
            j -= 1
        if i > j:
            break
        arr[i], arr[j] = arr[j], arr[i]
        i += 1
        j -= 1
    if l < j:
        qsort(arr, l, j)
    if i < r:
        qsort(arr, i, r)

def main():
    n = int(input())
    a = list(map(int, input().split()))
    qsort(a, 0, n-1)
    print_arr(a, n)

if __name__ == "__main__":
    main()
