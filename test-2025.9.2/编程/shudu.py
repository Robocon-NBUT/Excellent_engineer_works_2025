def shudu(shuzu:list[list[int]]):
    # 先遍历棋盘，获取棋盘上值为0的坐标
    kong_list = get_kong_list(shuzu)
    # 开始执行数独递归函数，从第一个棋盘上值为0的坐标开始递归
    if shudu_digui(shuzu,kong_list,0):
        for rows in shuzu:
            print(" ".join(map(str,rows)))
    else:
        pass

def shudu_digui(shuduqipan:list[list[int]],zuobiaos:list[list[int]],suoyin:int) -> bool:
    # 确定数独递归函数的终止条件，正确终止条件是填完最后一个值为0的空，
    if(suoyin == len(zuobiaos)):
        return True
    correct_list = get_correct_list(shuduqipan,zuobiaos[suoyin])
    # 错误终止条件是空处不存在可以填写的数
    if(len(correct_list) == 0):
        return False
    
    # 获取当前要填写空的位置
    x = zuobiaos[suoyin][1]
    y = zuobiaos[suoyin][0]
    # 确定可以填写空的数有哪些
    for number in correct_list:
        # 填写的数据进行尝试
        shuduqipan[y][x] = number
        # 看看这样子填写后面的操作成不成功
        result = shudu_digui(shuduqipan,zuobiaos,suoyin+1)
        # 看到后面的操作成功，就将操作成功的消息传递回去
        if(result == True):
            return True
        # 到了这一步，说明操作没有成功，需要将棋盘进行回溯
        shuduqipan[y][x] = 0
    # 如果遍历所有可以填写的数据也不成功，说明这一次操作不成功，将操作失败的消息传递回去
    return False

def get_kong_list(shuzu:list[list[int]]):
    kong_list = []
    for i in range(len(shuzu)):
        for j in range(len(shuzu[i])):
            if(shuzu[i][j] == 0):
                zuobiao = [0,0]
                zuobiao[0] = i
                zuobiao[1] = j
                kong_list.append(zuobiao)
    return kong_list

def get_correct_list(shuzu:list[list[int]],zuobiao:list[int]):
    # 创建[1……9]的数组
    correct_list =[i for i in range(1,len(shuzu )+1)]
    length = len(shuzu)
    size = int(length ** (1/2))
    # 获取当前的位置
    x = zuobiao[1]
    y = zuobiao[0]
    top = (y // size) * size
    left = (x // size) * size
    bottom = top + size
    right = left + size

    # 横向遍历，看看哪个不能填写
    for j in range(length):
        if shuzu[y][j] in correct_list:
            correct_list.remove(shuzu[y][j])
    # 纵向遍历，看看哪个不能填写
    for i in range(length):
        if shuzu[i][x] in correct_list:
            correct_list.remove(shuzu[i][x])
    # 周边遍历，看看哪个不能填写
    for i in range(top,bottom):
        for j in range(left,right):
            if shuzu[i][j] in correct_list:
                correct_list.remove(shuzu[i][j])
    
    return correct_list

def main():
    #获取要数独棋盘大小
    cols = rows = int(input())
    #接受数据，并创建棋盘
    old_shuzu = [[int(num) for num in input().split(" ")][0:cols] for _ in range(rows)]
    #利用shudu函数进行解题
    shudu(old_shuzu)

if __name__ == "__main__":
    main()