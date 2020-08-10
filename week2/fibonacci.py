# Uses python3
def calc_fib(n):
    a = []
    a[0] = 0
    a[1] = 1
    for i in range(2, n):
    	a[i] = a[i-1] + a[i-2]
   	
   	return (a[n])


n = int(input())
print(calc_fib(n))
