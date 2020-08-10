#include <iostream>

using std::cout;

int get_change(int m) {

  int min_num_coins[m+1];
  int coins[4] = {1, 3, 4};
  min_num_coins[0] = 0;
  for (int i=1; i<=m; i++){
  	min_num_coins[i] = 99999;
  	for(int j=0; j<3; j++){
  		if (i >= coins[j]){
  			int coin = coins[j];
  			int num_coins = min_num_coins[i - coin] + 1;
  			if (num_coins < min_num_coins[i]){
  				min_num_coins[i] = num_coins;
  			}
  		}
  	}
	}
	// for (int i=0; i<m; i++)
	// {
	// 	std::cout<< min_num_coins[i] << " ";
	// }
	// std::cout << '\n';
	return min_num_coins[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
