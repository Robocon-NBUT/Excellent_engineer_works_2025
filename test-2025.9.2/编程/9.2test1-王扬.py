def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quick_sort(left) + middle + quick_sort(right)


def main():
    try:
        n = int(input().strip())
        arr = list(map(int, input().split()))

        if len(arr) != n:
            print("错误：输入序列长度与指定长度不符")
            return

        sorted_arr = quick_sort(arr)
        print(" ".join(map(str, sorted_arr)))

    except ValueError:
        print("错误：请输入有效的整数序列")


if __name__ == "__main__":
    main()