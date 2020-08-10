# Uses python3

def fibonacci_sum_optimized(n):
    if n <= 1:
        return n

    new_n = (n + 2)%60
    if new_n == 1:
        return 0
    elif new_n == 0:
        return 9

    previous = 0
    current  = 1

    for _ in range(2, new_n + 1):
        c = current + previous
        c = c%10
        current, previous = c, current
    
    if c != 0:
        return c-1
    else:
        return 9

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum_optimized(n))
