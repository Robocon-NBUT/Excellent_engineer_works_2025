import random
with open("input.txt","w") as f:
    nums=[str(random.randint(0,2**32-1))for _ in range(5)]
    print("生成的数：”， “ ".join(nums))
    f.write(" ".join(nums))
    with open("input.txt") as f:
        avg=sum(map(int,f.read().split()))/5
        with open(f"output.txt","w") as out:
            out.write(f"{avg:.4f}")
        print(f"平均值：{avg:.4f}")
