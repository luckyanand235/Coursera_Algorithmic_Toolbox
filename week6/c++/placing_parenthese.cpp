#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <algorithm>

using std::vector;
using std::string;
using std::max;
using std::min;
using std::stoi;

long long min(int tmp, int a, int b, int c, int d) {

  long long minimum = 9999999999;

  if (tmp < minimum)
    minimum=tmp;
  if (a < minimum)
    minimum=a;
  if(b < minimum)
    minimum=b;
  if(c < minimum)
    minimum=c;
  if(d < minimum)
    minimum=d;

  return minimum;
}
long long max(int tmp, int a, int b, int c, int d) {

  long long maximum = -9999999999;

  if (tmp > maximum)
    maximum=tmp;
  if (a > maximum)
    maximum=a;
  if(b > maximum)
    maximum=b;
  if(c > maximum)
    maximum=c;
  if(d > maximum)
    maximum=d;

  return maximum;
}

//2d vector printing
void print(vector<vector<long long>> v)
{
  std::cout << "Printing array:\n";
  for (auto x : v)
  {
    for (auto y : x)
    {

      std::cout << y << " ";
    }
    std::cout << "\n";
  }
  std::cout << "\n";
}



long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

vector<long long> MinAndMax(vector<vector<long long>> m, vector<vector<long long>> M, string operation, int i, int j){
  long long temp_min = 9999999999;
  long long temp_max = -9999999999;

  for (int k=i; k<j; k++){
    // std::cout << operation[k]<< "\n";
    long long a = eval(M[i][k], m[k + 1][j], operation[k]);
    long long b = eval(m[i][k], m[k + 1][j], operation[k]);
    long long c = eval(M[i][k], M[k + 1][j], operation[k]);
    long long d = eval(m[i][k], M[k + 1][j], operation[k]);

    temp_min = min(temp_min, a, b, c, d);
    temp_max = max(temp_max, a, b, c, d);
    //std::cout << "temp_min " << temp_min << "temp_max " << temp_max << '\n';
  }
  vector<long long> ret;
  ret.push_back(temp_min);
  ret.push_back(temp_max);
  // for (i=0; i<2; i++)
  //   std::cout << ret[i] << " ";

  return ret;
}

long long get_maximum_value(const string &exp) {
  //write your code here
  string operation = "";
  for (size_t i=0; i<exp.size(); i++){
    if (i%2 != 0){
      operation += exp[i];
    }
  }
  string datanum = "";
  for (size_t i=0; i<exp.size(); i++){
    if (i%2 == 0){
      datanum += exp[i];
    }
  }

  // std::cout << datanum << '\n';
  // std::cout << operation << '\n';
  // std::cout << stoi(datanum) << '\n';
  int n = datanum.size();
  vector<vector<long long>> m(n, vector<long long> (n, 0));
  vector<vector<long long>> M(n, vector<long long> (n, 0));

  int datanum_1 = stoi(datanum);
  for (int i=n-1; i>=0; i--){
      m[i][i] = datanum_1%10;
      M[i][i] = datanum_1%10;
      datanum_1 /= 10;
  }

  for (int s=1; s<n; s++){
    for(int i=0; i<n-s; i++){
      int j = i + s;
      vector<long long> v = MinAndMax(m, M, operation, i, j);
      m[i][j] = v[0];
      M[i][j] = v[1];
    }
  }
  // print(m);
  // print(M);

  return M[0][n - 1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
