def bubble_sort(array):


    for i in range(1, len(array)):

        for j in range(0, len(array) - i):

            if array[j] > array[j + 1]:

                array[j], array[j + 1] = array[j + 1], array[j]

    return array

if __name__ == '__main__':
    n = int(input().strip())
    arr = list(map(int, input().split()))

    print(bubble_sort(arr))
