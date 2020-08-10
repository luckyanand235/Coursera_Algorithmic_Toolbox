#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int numRefills = 0;
    int currentRefill = 0;
    int n = stops.size();
    int stop[n+2];
    stop[0] = 0;
    stop[n+1] = dist;
    for (int i=1; i<=n; i++)
        stop[i] = stops[i-1];

    while (currentRefill <= n){
        int lastRefill = currentRefill;
        
        while (currentRefill <= n && (stop[currentRefill + 1] - stop[lastRefill]) <= tank){
            currentRefill = currentRefill + 1;
        }

        if (currentRefill == lastRefill)
            return -1;
        if (currentRefill <= n)
            numRefills = numRefills + 1;
    }

    return numRefills;
}


int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
