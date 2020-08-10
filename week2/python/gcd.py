# Uses python3

def gcd_optimized(a, b):
    if b == 0:
    	return a
    else:
    	if a >= b:
    		return gcd_optimized(b, a%b)
    	else:
    		return gcd_optimized(a, b%a)


if __name__ == "__main__":
    a, b = map(int, input().split())
    print(gcd_optimized(a, b))
