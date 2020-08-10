# Uses python3
import math
def fibonacci(n):
    a, b = 0, 1
    for _ in range(2, n+1):
        c = a+b
        c = c% 10
        b, a = c, b
    return c

def fibonacci_sum_squares_optimized(n):
    new_n = n%60
    new_n1 = (n+1)%60

    if new_n <= 1:
    	a = new_n
    else:
    	a = fibonacci(new_n)
    if new_n1 <= 1:
    	b = new_n1
    else:
    	b = fibonacci(new_n1)
    return (a*b)%10

if __name__ == '__main__':
    n = int(input())
    print(fibonacci_sum_squares_optimized(n))