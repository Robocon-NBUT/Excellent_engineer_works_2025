def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1, -1, -1):
        for j in range(0, i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

def main():
    n = int(input().strip())
    arr = list(map(int, input().split()))
    bubble_sort(arr)
    print(" ".join(map(str, arr)))
if __name__ == "__main__":
    main()
