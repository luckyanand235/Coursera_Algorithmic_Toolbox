#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;

int main(){
	int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }

	cout << "Digits are "; 
	for (int i=0; i<n; i++){
		cout << a[i] << " ";
	}
	cout << "\n";

	cout << "Before erasing Digits size : "<< a.size() << "\n";
	a[3].erase();
	cout << "After erasing Digits size : "<< a.size();
	
	// for (int i=0; i<n; i++){
	// 	cout << a[i] << ", ";
	// }
	cout << "\n";

	cout<< "Digits are digits : ";
	for(int i=0; i<n; i++){
		cout << a[i] << ", ";
	}
	int i=0;
	

	cout << "Removed all elements : \n";
	cout<< a.empty();
	return 0;

}