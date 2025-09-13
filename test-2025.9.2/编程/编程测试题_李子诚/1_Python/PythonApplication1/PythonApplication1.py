def quick_sort(li):
    if len(li)<=1:
        return li
    pivot=li[len(li)//2]
    left=[x for x in li if x<pivot]
    middle=[x for x in li if x==pivot]
    right=[x for x in li if x>pivot]
    return quick_sort(left) + middle +quick_sort(right)

a=int(input())
li=list(map(int,input().split()))
final=quick_sort(li)
print(' '.join(map(str,final)))