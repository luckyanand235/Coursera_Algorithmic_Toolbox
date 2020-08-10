#include <iostream>

int fibonacci_sum_optimized(long long n) {
    if (n <= 1)
        return n;
    int new_n = (n+2)%60;
    if (new_n == 1)
        return 0;
    else if (new_n == 0)
        return 9;


    long long previous = 0;
    long long current  = 1;
    long long c;
    for (long long i = 2; i < new_n + 1; ++i) {
        c = current + previous;
        c = c % 10;
        previous = current;
        current = c;
    }
    if (c != 0)
        return (c-1);
    else
        return 9;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_optimized(n) << "\n";
}
