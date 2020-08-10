#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> optimal_sequence_corrected(int n){

  std::vector<int> sequence;
  sequence.push_back(n);
  
  while (n >= 1){

    if (n%4 == 0){
      n = n/2;
      sequence.push_back(n);
    }

    else if (n%3 == 0){
      n = n/3;
      sequence.push_back(n);
    }

    else if((n % 2 == 0) && (n%4 != 0)){
      n -= 1;
      sequence.push_back(n);
    }

  }

return sequence;

}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
