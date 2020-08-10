# Uses python3
import sys

def get_majority_element(a, left, right):
    
    a.sort()
    mid = left + (right-left)//2
    count = 0
    for i in a:
        if a[mid] == i:
            count += 1
    if count > len(a)//2:
        return 1
    
    return -1



if __name__ == '__main__':
    n = int(input())
    a = list(map(int, input().split()))

    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)