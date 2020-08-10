#include <iostream>

long long gcd_optimized(long long a, long long b) {
  if (b == 0)
    return a;
  else{
    if (a >= b)
      return gcd_optimized(b, a%b);
    else
      return gcd_optimized(a, b%a);
  }
}

int main() {
  long long a, b;
  std::cin >> a >> b;
  std::cout << gcd_optimized(a, b) << std::endl;
  return 0;
}
