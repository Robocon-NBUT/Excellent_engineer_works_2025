def shudu(shuzu:list[list[int]]):
    kong_list = get_kong_list(shuzu)
    if shudu_digui(shuzu,kong_list,0):
        for rows in shuzu:
            print(" ".join(map(str,rows)))
    else:
        pass
def shudu_digui(shuzu:list[list[int]],zuobiaos:list[list[int]],index:int) -> bool:
    if(index == len(zuobiaos)):
        return True
    correct_list = get_correct_list(shuzu,zuobiaos[index])
    if(len(correct_list) == 0):
        return False
    x = zuobiaos[index][1]
    y = zuobiaos[index][0]
    for number in correct_list:
        shuzu[y][x] = number
        result = shudu_digui(shuzu,zuobiaos,index+1)
        if(result == True):
            return True
        shuzu[y][x] = 0
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
    correct_list =[i for i in range(1,len(shuzu )+1)]
    length = len(shuzu)
    size = int(length ** (1/2))
    x = zuobiao[1]
    y = zuobiao[0]
    top = (y // size) * size
    left = (x // size) * size
    bottom = top + size
    right = left + size


    for j in range(length):
        if shuzu[y][j] in correct_list:
            correct_list.remove(shuzu[y][j])
    for i in range(length):
        if shuzu[i][x] in correct_list:
            correct_list.remove(shuzu[i][x])
    for i in range(top,bottom):
        for j in range(left,right):
            if shuzu[i][j] in correct_list:
                correct_list.remove(shuzu[i][j])
    
    return correct_list





def main():
    cols = rows = int(input())
    old_shuzu = [[int(num) for num in input().split(" ")][0:cols] for _ in range(rows)]
    shudu(old_shuzu)


if __name__ == "__main__":
    main()