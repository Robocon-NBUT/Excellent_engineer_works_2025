f=open("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\intput.txt.txt","w",encoding="UTF-8")
f.write("1 2 3 4 5")
f1=open("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\intput.txt.txt","r",encoding="UTF-8")
for line in f1:
    word=line.split(" ")
    sum=sum+word
    print(word)

s=sum/5
f2=open("D:\\新建文件夹\\Excellent_engineer_works_2025\\work_1\\content\\output.txt.txt","w",encoding="UTF-8")
f2.write(s)
f.close()
f1.close()
f2.close()