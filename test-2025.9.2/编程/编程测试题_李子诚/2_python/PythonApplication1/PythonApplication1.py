def is_valid(area,row,column,num,n):
    for i in range(n):
        if area[row][i]==num:
            return False
    for i in range(n):
        if area[i][column]==num:
            return False
    box_size=int(n**0.5)
    start_row=row//box_size*box_size
    start_column=column//box_size*box_size
    for i in range(box_size):
        for j in range(box_size):
            if area[start_row+i][start_column+j]==num:
                return False
    return True

def solve_sudoku(area,n):
    for row in range(n):
        for column in range(n):
            if area[row][column]==0:
                for num in range(1,n+1):
                    if is_valid(area,row,column,num,n):
                        area[row][column]=num
                        if solve_sudoku(area,n):
                            return True
                        area[row][column]=0
                return False
    return True

n=int(input())
area=[]
for _ in range(n):
    _row_=list(map(int,input().split()))
    area.append(_row_)
solve_sudoku(area,n)
for _row_ in area:
    print(" ".join(map(str,_row_)))
