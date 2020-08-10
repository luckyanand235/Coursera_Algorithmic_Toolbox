# Uses python3
import numpy as np
import math
def fibonacci(n):
	phi1 = (1 + math.sqrt(5)) / 2
	#phi2 = (1 - math.sqrt(5)) / 2
	return round(pow(phi1, n) / math.sqrt(5)) % 10

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
	while True:
		n = np.random.randint(0, 100)
		a = fibonacci(n)%10
		b = get_fibonacci_last_digit_optimized(n)
		if a != b:
			break
		print("a = ", a, " b = ", b, "OK!!!")

	print("For n = ",n, " fibonacci value digits a , b", a, b)
