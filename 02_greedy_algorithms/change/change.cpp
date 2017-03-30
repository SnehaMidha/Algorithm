/*Task. The goal in this problem is to find the minimum number of coins needed to change the input value
(an integer) into coins with denominations 1, 5, and 10.*/

#include <iostream>
int get_change(int m) {
	int n=0;
	n=m/10;
	m=m%10;
	n+=m/5;
	m=m%5;
	n+=m;	
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
