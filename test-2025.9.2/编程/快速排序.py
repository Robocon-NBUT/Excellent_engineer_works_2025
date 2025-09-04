def px(num):
    if len(num) <= 1:
        return num
    n=num[len(num) // 2]
    l=[x for x in num if x < n]
    m=[x for x in num if x == n]
    r=[x for x in num if x > n]
    return px(l)+m+px(r)

def main():
    n=input()
    num = list(map(int,input().split()))
    result=px(num)
    print(' '.join(map(str,result)))

if __name__ == '__main__':
    main()