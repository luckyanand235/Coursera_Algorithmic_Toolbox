#include <iostream>
#include <vector>

using std::vector;

long long merge_and_get_inversion(vector<int> &a, vector<int> &a_sorted, size_t low, size_t mid, size_t high){

  int k = low, i = low, j = mid + 1;
  int inversion_count = 0;

  while (i <= mid && j <= high){

    if (a[i] <= a[j]){
      a_sorted[k++] = a[i++];
    }
    else{
      a_sorted[k++] = a[j++];
      inversion_count += (mid - i + 1);
    }
  }

  while (i <= mid)
    a_sorted[k++] = a[i++];

  for (int i=low; i<=high; i++)
    a[i] = a_sorted[i];

  return inversion_count;

}


long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right == left) 
    return 0;

  size_t mid = left + ((right - left) / 2);
  number_of_inversions += get_number_of_inversions(a, b, left, mid);
  number_of_inversions += get_number_of_inversions(a, b, mid + 1, right);
  //write your code here
  number_of_inversions += merge_and_get_inversion(a, b, left, mid, right);
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b = a;
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
