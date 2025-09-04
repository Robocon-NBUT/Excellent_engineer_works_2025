def bubble_sort(arr,n):

    # 外层循环
    for i in range(n):
        swapped = False
        # 内层循环 
        for j in range(0, n-i-1):
            if arr[j] > arr[j+1]:
                arr[j], arr[j+1] = arr[j+1], arr[j]
                swapped = True
        if not swapped: 
            break   

def main():
    n=int(input().strip())

    nums=list(map(int,input().strip().split()))
    bubble_sort(nums,n)
    print(" ".join(map(str,nums)))

if __name__ == "__main__":
    main()