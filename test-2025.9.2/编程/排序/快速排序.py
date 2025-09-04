def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[0]
        less = [x for x in arr[1:] if x <= pivot]
        greater = [x for x in arr[1:] if x > pivot]
        return quick_sort(less) + [pivot] + quick_sort(greater)

def main():
    n = int(input("请输入序列长度: "))
    sequence = list(map(int, input("请输入序列，以空格分隔: ").split()))
    sorted_sequence = quick_sort(sequence)
    print(" ".join(map(str, sorted_sequence)))

if __name__ == "__main__":
    main()