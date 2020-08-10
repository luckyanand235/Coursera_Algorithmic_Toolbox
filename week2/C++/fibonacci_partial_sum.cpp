#include <iostream>
#include <vector>
#include <cmath>
using std::vector;
long long fibonacci(long long n){
    double phi = (1 + sqrt(5)) / 2; 
  return round(pow(phi, n) / sqrt(5));
}

long long get_fibonacci_partial_sum_optimized(long long from, long long to) {
    long long from_new = from + 1;
    long long from_sum = fibonacci(from_new) - 1;
    long long to_new = to + 2;
    long long to_sum = fibonacci(to_new) -1;
    long long dif = to_sum - from_sum;
    return dif % 10;

}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout <<get_fibonacci_partial_sum_optimized(from, to) << '\n';
}
