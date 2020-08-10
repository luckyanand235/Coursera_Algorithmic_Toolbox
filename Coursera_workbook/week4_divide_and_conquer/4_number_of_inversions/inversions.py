# Uses python3
import sys

def merge_and_get_inversion(a, b, left, right, ave):
    aux = []
    inversion_count = 0
    while len(a) != 0 or len(b) != 0:
        if a[0] <= b[0]:
            aux.append(a[0])
            del a[0]
        elif a[0] > b[0]:
            aux.append(b[0])
            inversion_count += 1
            del b[0]
    while len(a)!=0:
        aux.append[a[0]]
        del a[0]
    while len(b)!=0:
        aux.append(b[0])
        del b[0]
    return inversion_count
    
def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 1:
        return number_of_inversions
    ave = (left + right) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave, right)
    #write your code here
    return number_of_inversions

if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)))
