import random,numpy

with open("input.txt",'w') as outFile:
    for i in range(5):
        shuju = random.randint(0,2**32 - 1)
        outFile.write(str(shuju) + ' ')
        if(i == 0):
            print("input:")
        print(str(shuju)+' ', end='')
    print()



with open("input.txt",'r') as inFile:
    A = inFile.read()
    B = A.split()
    C = [float(num) for num in B ]
    print("output:")
    print(numpy.float32(sum(C)/len(C)))
    with open("output.txt",'w') as shuchu:
        shuchu.write(str(numpy.float32(sum(C)/len(C))) + ' ')
