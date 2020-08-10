#include <iostream>

long long gcd(long long a, long long b){
  	if (b == 0)
  		return a;
  	else{
  		if (a >= b)
  			return gcd(b, a%b);
  		else
  			return gcd(a, b%a);
  	}	
  }

long long lcm_optimized(long long a, long long b) {
  long hcf = 1;
  
  hcf = gcd(a, b);
  long long lcm = (a*b)/hcf;
  return lcm;
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << lcm_optimized(a, b) << std::endl;
  return 0;
}
