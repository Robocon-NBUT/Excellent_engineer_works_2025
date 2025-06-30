import random

def mean(data):
    return sum(data)/len(data)

def main():
    rand_num=[random.randint(1,100) for _ in range(5)]
    print(' '.join(map(str, rand_num)))
    with open("input.txt","w")as f:
        f.write(" ".join(str(num) for num in rand_num))
    with open("input.txt","r")as f:
        data=[int(num) for line in f if line.strip() for num in line.strip().split()]
    result=mean(data)
    with open("output.txt","w")as f:
        f.write(f'{result}')
        print(result)

if __name__ == '__main__':
    main()