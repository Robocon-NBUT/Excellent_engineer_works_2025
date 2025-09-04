def MergeSort(shuzu:list,left:int,right:int,temp:list):
    if(left < right):
        middle = int((left + right)/2 - 0.5)
        MergeSort(shuzu,left,middle,temp)
        MergeSort(shuzu,middle+1,right,temp)
        pl = left
        pr = middle + 1
        while(pl <= middle and pr <= right):
            if(shuzu[pl] < shuzu[pr]):
                temp[pl - left + pr - (middle + 1)] = shuzu[pl]
                pl+=1
            else:
                temp[pl - left + pr - (middle + 1)] = shuzu[pr]
                pr+=1
        while(pl <= middle):
            temp[pl - left + right  - middle] = shuzu[pl]
            pl+=1
        while(pr <= right):
            temp[pr - left] = shuzu[pr]
            pr+=1
        for i in range(left,right+1):
            shuzu[i] = temp[i - left]

def UseMergeSort(shuzu:list):
    shuzu_length = len(shuzu)
    copy_shuzu = [num for num in shuzu]
    temp_shuzu = [0 for _ in range(shuzu_length)]
    MergeSort(copy_shuzu,0,shuzu_length-1,temp_shuzu)
    return copy_shuzu

def main():
    input_number = input()
    old =[int(number) for number in input().split(" ")]
    old = old[0:int(input_number)]
    new = UseMergeSort(old)
    print(" ".join(map(str,new)),end="")

if __name__ == "__main__":
    main()
