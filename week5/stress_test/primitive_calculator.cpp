#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <bits/stdc++.h>

using std::vector;


// Algorithm 1

vector<int> optimal_sequence_corrected(int n){

  std::vector<int> sequence;
  sequence.push_back(n);
  
  while (n > 1){
    if (n%3 == 0){
      n = n/3;
      sequence.push_back(n);
    }
    else if (n%2 == 0){
    
      if ((n%4 == 0)){
        n = n/2;
        sequence.push_back(n);
      }
      else if(((n/2)-1)%3 == 0){
        n = n/2;
        sequence.push_back(n);
          if (n > 1){
          n = n-1;
          sequence.push_back(n);
        }
      }
      else if (((n/2)-2)%3 == 0){
        n = n/2;
        sequence.push_back(n);
        if (n > 1){
          n -= 1;
          sequence.push_back(n);
        }
        if (n > 1){
          n -= 1;
          sequence.push_back(n);
        }
      }
    } 
    else {
      n -= 1;
      sequence.push_back(n);
    }
  }
  reverse(sequence.begin(), sequence.end());
return sequence;
}

// Algorithm 2

void print(vector<int> v, std::string s)
{
  std::cout << s << ":";
  for (auto x : v)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
}


vector<int> dp_sequence(int n)
{
  vector<int> dp = {0};
  vector<int> sequence;
  vector<int> operations = {1};
  if (n == 1)
  {
    sequence.push_back(1);
    return sequence;
  }
  for (int i = 2; i <= n; i++)
  {
    int res1 = 999999;
    int res2 = 999999;
    int res3 = 999999;
    res1 = dp[i - 2];
    if (i % 2 == 0)
    {
      res2 = dp[(i / 2) - 1];
    }
    if (i % 3 == 0)
    {
      res3 = dp[(i / 3) - 1];
    }
    if (res3 <= res2 && res3 <= res1)
    {
      operations.push_back(3);
      dp.push_back(res3 + 1);
    }
    else if (res2 <= res1 && res2 <= res3)
    {
      operations.push_back(2);
      dp.push_back(res2 + 1);
    }
    else if (res1 <= res2 && res1 <= res3)
    {
      operations.push_back(1);
      dp.push_back(res1 + 1);
    }
  }

  // sequence.push_back(start);
  int i = n;
  while (i >= 1)
  {
    sequence.push_back(i);
    if (operations[i - 1] == 1)
    {
      i -= 1;
    }
    else if (operations[i - 1] == 2)
    {
      i /= 2;
    }
    else
    {
      i /= 3;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

// int max(int a, int b){
//   if (a >= b)
//     return a;
//   else
//     return b;
// }


int main(){
  while (true){
    int n = 0;
    n = 1 + rand() % 100;
    bool flag = false;
    vector<int> sequence_algo_1 = optimal_sequence_corrected(n);
    vector<int> sequence_algo_2 = dp_sequence(n);
    if (sequence_algo_1.size() == sequence_algo_2.size()){
      for (int i=0; i<sequence_algo_1.size(); i++){
        if (sequence_algo_1[i] != sequence_algo_2[i]){
          flag = true;
          break;
        }
      }
    if (flag == true){

      std::cout << "n : " << n << '\n';
      std::cout << "Sequence Algorithm 1 : ";
      for(int i=0; i<sequence_algo_1.size(); i++){
        std::cout << sequence_algo_1[i] << " ";
      }
      std::cout << '\n';
      std::cout << "Sequence Algorithm 2 : ";
      for(int i=0; i<sequence_algo_2.size(); i++){
        std::cout << sequence_algo_2[i] << " ";
      }
        std::cout << '\n';
    }
    else {
      std::cout << "OK!!" << "\n";
      }
    }
    else{
      
      std::cout << "n : " << n << '\n';
      std::cout << "Sequence Algorithm 1 : ";
      for(int i=0; i<sequence_algo_1.size(); i++){
        std::cout << sequence_algo_1[i] << " ";
      }
      std::cout << '\n';
      std::cout << "Sequence Algorithm 2 : ";
      for(int i=0; i<sequence_algo_2.size(); i++){
        std::cout << sequence_algo_2[i] << " ";
      }
      std::cout << '\n';
      break;
    }
  }
}
// int main() {
//   int n;
//   std::cin >> n;
//   vector<int> sequence = optimal_sequence_corrected(n);
//   std::cout << sequence.size() - 1 << std::endl;
//   for (size_t i = 0; i < sequence.size(); ++i) {
//     std::cout << sequence[i] << " ";
//   }
// }
