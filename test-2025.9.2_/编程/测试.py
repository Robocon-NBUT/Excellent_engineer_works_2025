def quick_sort(arr):
    if len(arr)<=1:
        return arr
    a=arr[len(arr)//2]
    left=[x for x in arr if x<a]
    middle=[x for x in arr if x==a]
    right=[x for x in arr if x>a]
    return quick_sort(left)+middle+quick_sort(right)
n=int(input("请输入数字数目"))
r=input('请输入数字，中间以空格分隔')
arr=list(map(int,r.split()))
if len(arr)!=n:
    print("数目不相符")
else:
    arr_new=quick_sort(arr)
    print(" ".join(map(str,arr_new)))