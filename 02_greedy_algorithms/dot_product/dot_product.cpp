/*Task. Given two sequences a 1 , a 2 , . . . , a n (a i is the profit per click of the i-th ad) and b 1 , b 2 , . . . , b n (b i is
the average number of clicks per day of the i-th slot), we need to partition them into n pairs (a i , b j )
such that the sum of their products is maximized.*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b) {
 
  sort(a.begin(),a.end(),std::greater<int>());
  sort(b.begin(),b.end(),std::greater<int>());
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
}
