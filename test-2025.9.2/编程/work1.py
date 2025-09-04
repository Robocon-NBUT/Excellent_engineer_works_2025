def bubble_sort(arr):
    n = len(arr)
    for i in range(n - 1):
        for j in range(n - 1 - i):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    return arr
if __name__ == "__main__":
    n = int(input().strip())
    nums = list(map(int, input().strip().split()))
    sorted_nums = bubble_sort(nums)
    print(" ".join(map(str, sorted_nums)))

