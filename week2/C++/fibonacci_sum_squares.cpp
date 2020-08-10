#include <iostream>
#include <cmath>
long long fibonacci(long long n){
    double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5));
}

int fibonacci_sum_squares_optimized(long long n) {
    long long fib_current = fibonacci(n);
    long long fib_next = fibonacci(n+1);
    long long square_sum = fib_current * fib_next;
    std::cout<< "Squared Sum : " << square_sum << "\n";
    return square_sum % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_optimized(n);
}
