#include <iostream>

int get_change(int m) {
  int tens = 0;
  int fives = 0;
  int ones = 0;
  tens = m/10;
  m = m%10;
  fives = m/5;
  m = m%5;
  ones = m;

  return (tens + fives + ones);
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
