import random
nums = [random.randint(1, 100) for _ in range(5)]
try:
    with open("input.txt", "w") as f:
        f.write(" ".join(map(str, nums)))
except Exception as e:
    print(f"写入文件时出错: {e}")
try:
    with open("input.txt", "r") as f:
        content = f.read()
        print(content)
        nums1 = list(map(int, content.split()))
        average = sum(nums1) / len(nums1)
        try:
            with open("output.txt", "w") as v:
                v.write(f"{average}")
        except Exception as e:
            print(f"写入文件时出错: {e}")
except Exception as e:
    print(f"读取文件时出错: {e}")
try:
    with open("output.txt", "r") as f:
        content = f.read()
        print(content)
except Exception as e:
    print(f"读取文件时出错: {e}")

        
        
        
