#include <iostream>

int gcd(int a, int b){
	int current_gcd=a;
	int rem,div;
	div=b;
	if(a==0)
		return b;
	if(b==0)
		return a;
	rem=div%current_gcd;
	while(rem!=0){
		div= current_gcd;
		current_gcd=rem;
		rem=div%current_gcd;
	}
	return current_gcd;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {

  return ((long long) a * b)/gcd(a, b);
}

int main() {
  int a, b;
  std::cin >> a >> b;
  std::cout << lcm_fast(a, b) << std::endl;
  return 0;
}
