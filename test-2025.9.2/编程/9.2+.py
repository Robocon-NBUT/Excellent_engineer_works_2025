n=int(input('请输入4或9'))
sd=[]
for i in range(n):
    data=input()
    data=data.split(' ')
    sd.append(data)
def pdh(a):
    p=0
    d=0
    for c in range(n):
        if(sd[a][c]=='0'):
            p+=1
            q=c
        d+=int(sd[a][c])
    if (p==1):
        if(n==4):
            sd[a][q]=str(10-d)
        else:
            sd[a][q]=str(45-d)
        return int(sd[a][q])
    else:
        return 0
def pdl(b):
    p=0
    d=0
    for c in range(n):
        if(sd[c][b]=='0'):
            p+=1
            q=c
        d+=int(sd[c][b])
    if (p==1):
        if(n==4):
            sd[q][b]=str(10-d)
        else:
            sd[q][b]=str(45-d)
        return int(sd[q][b])
    else:
        return 0
def pdq(a,b):
    p=0
    d=0
    for e in range(a,a+2):
        for r in range(b,b+2):
            if(sd[e][r]=='0'):
                p+=1
                o=e
                p=r
            d+=int(sd[e][r])
    if (p==1):
        if(n==4):
            sd[o][p]=str(2)
        else:
            sd[o][p]=str(45-d)
        return int(sd[o][p])
    else:
        return 0
s=0
for i in range(n):
    for j in range(n):
        s+=int(sd[i][j])
while not ((s==40 and n==4)or(s==405 and n==9)):
    for i in range(n):
        s+=pdh(i)
    for j in range(n):
        s+=pdl(j)
    for i in range(int(n**0.5)):
        for j in range(int(n**0.5)):
            s+=pdq(int(i*n**0.5),int(j*n**0.5-1))
    for i in range(n):
        for j in range(n-1):
            print(sd[i][j]+' ',end='')
        print(sd[i][n-1])
