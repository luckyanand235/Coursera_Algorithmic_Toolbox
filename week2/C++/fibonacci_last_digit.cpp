#include <iostream>

long long get_fibonacci_last_digit_optimized(int n) {

    long long previous = 0;
    long long current  = 1;
    for (int i = 1; i < n; ++i) {
        long long temp = previous + current;
        previous = current;
        current = temp;
    }

    return current % 10;
}

int main() {
    int n;
    std::cin >> n;
    long long c = get_fibonacci_last_digit_optimized(n);
    std::cout << c << '\n';
    }
