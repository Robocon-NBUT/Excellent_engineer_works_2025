def bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        for j in range(n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
    return arr

nums = list(map(int, input("请输入数字，用空格分隔：").split(' ')))

sorted_nums = bubble_sort(nums)
print("排序后：", sorted_nums)
