# Uses python3
from numpy import random

def binary_search(a, x):
    left, right = 0, len(a)-1
    # write your code here
    while left <= right:
        mid = left + (right - left)//2
        if a[mid] == x:
            while a[mid-1] == x:
                if mid == 0:
                    break
                else:
                    mid -= 1

            return mid
        elif a[mid] > x:
            right = mid  - 1
        else:
            left = mid + 1
    return -1

def linear_search(a, x):
    for i in range(len(a)):
        if a[i] == x:
            return i
    return -1

if __name__ == '__main__':

    while True:
        n = random.randint(1, 10)
        a = []
        for i in range(n):
            a.append(random.randint(1, 10))

        a.sort()
        x = random.randint(1, 10)

        res_linear = linear_search(a, x)
        res_binary = binary_search(a, x)

        if res_binary != res_linear:
            print('Array : ',a)
            print('Key : ',x)
            print('binary_search : ',res_binary)
            print('linear_search : ',res_linear)
            break;
        else:
            print('OK!!')