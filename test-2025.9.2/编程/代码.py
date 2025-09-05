def px(arr):
    n=len(arr)
    for i in range(n):
        for j in range(0,n-i-1):
            if arr[j]>arr[j+1]:
                arr{j},arr[j+1}=arr[j+1],arr{j]
    return arr
def main():
    n=int(input().strip())
    arr=list(map(int,input()split))
    if len(arr)!=n:
        print("输入错误")
        return
    print(arr)
            
