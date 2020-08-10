# Uses python3
def pisanoPeriod(m):
    previous , current = 0, 1
    for i in range(0, m*m):
        previous, current = current, (current + previous) % m
        if (previous == 0 and current == 1):
            return i + 1
    return 1

def get_fibonacci_huge_optimized(n, m):
    pisanoperiod = pisanoPeriod(m)
    n = n % pisanoperiod
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(get_fibonacci_huge_optimized(n, m))
