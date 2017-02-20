/*Task. Given two integers a and b, find their greatest common divisor.*/
#include <iostream>

int gcd_naive(int a, int b) {
	int current_gcd = 1;
	for (int d = 2; d <= a && d <= b; d++) {
		if (a % d == 0 && b % d == 0) {
			if (d > current_gcd) {
				current_gcd = d;
			}
		}
	}
	return current_gcd;
}

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

int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << gcd_naive(a, b) << std::endl;
 std::cout << gcd(a, b) << std::endl;
	return 0;
}
