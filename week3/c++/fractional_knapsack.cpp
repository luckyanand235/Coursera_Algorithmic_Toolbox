#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using std::vector;
using std::greater;
using std::swap;

double round(double var) 
{ 
    double value = (int)(var * 10000 + .5); 
    return (double)value / 10000; 
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0000;
  // write your code here
  int n = values.size();
  int a = 0;
  vector<float> v_per_w(n);
  for(int i=0; i<n; i++){

    v_per_w[i] = float(values[i])/float(weights[i]);
    
  }
  for (int i = n; i >= 0; i--)  
        for (int j = n; j > n - i; j--)  
            if (v_per_w[j] > v_per_w[j - 1]){  
                swap(v_per_w[j], v_per_w[j-1]); 
                swap(weights[j], weights[j-1]);
              }

  for(int i=0; i<n; i++){
    if (capacity == 0)
      return value;

    if (weights[i] > capacity)
      a = capacity;
    else
      a = weights[i];
    value += a*v_per_w[i];
    capacity -= a;
    value = round(value);
  }
  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
