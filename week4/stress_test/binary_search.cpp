#include <iostream>
#include <cassert>
#include <vector>
#include <random>
#include <bits/stdc++.h>

using std::vector;
using std::sort;

int binary_search(vector<int> &a, int x)
{
int left = 0, right = (int)a.size(); 

  while (left <= right){
    int mid = left + (int)(right-left)/2;

    if (x == a[mid]){
      while (a[mid - 1] == x){
        if (mid != 0)
          mid -= 1;
      }
      return mid;
    }
    else if (x < a[mid])
      right = mid-1;
    else
      left = mid+1;
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  while (true){
    int n = 1 + rand() % 10000;
    vector<int> a(n);
    for (int i=0; i<n; i++){
      a[i] = rand() % 10000;
    }
    sort(a.begin(), a.end());
    int x = rand() % 10000;
    int linear_out = linear_search(a, x);
    int binary_out = binary_search(a, x);
    if (linear_out == binary_out){
      std::cout<< "OK!!" << "\n";
    }
    else{
      std::cout << "Array : ";
      for (int i=0; i<n; i++){
        std::cout << a[i] << " ";
      }

      std::cout<< "\n";
      std::cout<< "element : " << x << "\n";

      std::cout << "linear_output : " << linear_out << "\n";      
      std::cout << "binary_output : " << binary_out << "\n";
      break;
    }
  }
}
