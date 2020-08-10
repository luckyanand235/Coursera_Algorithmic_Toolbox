#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  int candies = n;
  vector<int> summands;
  for(int i=1; i<=n; i++){
    int left = candies - i;
    bool flag = true;
    for (int j=0; j<summands.size(); j++){
      if (left == summands[j])
        flag = false;
    }
    if (left == i)
      flag = false;

    if (flag == true){
      candies = left;
      summands.push_back(i);
    }
    if(candies == 0)
      break;
  }

  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
