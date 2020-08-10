# Uses python3
import math
def fibonacci(n):
    a,b = 0, 1
    for i in range(2,n+1):
        c = a+b
        c = c%10
        b, a = c, b
    return (c-1)

def fibonacci_partial_sum_naive(from_, to):
    if to <= 1:
        return to
    new_from = (from_ + 1) % 60
    new_to = (to + 2) % 60

    if new_to <= 1:
        a = new_to - 1
    else:
        a = fibonacci(new_to)
    if new_from <= 1:
        b = new_from - 1
    else:
        b = fibonacci(new_from)

    if a >= b:
        return a-b
    else:
        return 10+a-b


if __name__ == '__main__':
    from_, to = map(int, input().split())
    print(fibonacci_partial_sum_naive(from_, to))