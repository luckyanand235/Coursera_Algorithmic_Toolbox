# Uses python3
import math
def get_fibonacci_last_digit_optimized(n):
    if n <= 1:
    	return n

    previous = 0
    current = 1
    temp = 0
    for _ in range(1, n):
    	temp = current + previous
    	temp = temp%10
    	current, previous = temp, current
    return temp

if __name__ == '__main__':
    n = int(input())
    print(get_fibonacci_last_digit_optimized(n))
