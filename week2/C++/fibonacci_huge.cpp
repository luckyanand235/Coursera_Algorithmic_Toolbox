#include <iostream>

int pisanoPeriod(int m){
    int a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
    return 1;
    
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    
    int pisanoperiod = pisanoPeriod(m);
    //std::cout<< " pisanoperiod : " << pisanoperiod;
    n = n % pisanoperiod;
    std::cout<< " pisanoperiod : " << pisanoperiod<< "\n"; 
    long long previous = 0;
    long long current  = 1;

    if (n <= 1){
        return n;
    }

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

int main() {
    long long n;
    int m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
