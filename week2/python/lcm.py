# Uses python3
def gcd(a, b):
	if b == 0:
		return a
	else:
		if a >= b:
			return gcd(b, a%b)
		else:
			return gcd(a, b%a) 

def lcm_optimized(a, b):
    hcf = gcd(a, b)
    
    return a*b//hcf

if __name__ == '__main__':
    a, b = map(int, input().split())
    print(lcm_optimized(a, b))

