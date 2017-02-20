/*Task. Given an integer n, find the last digit of the sum F 0 + F 1 + · · · + F n .*/
#include <iostream>

int fibonacci_sum_naive(long long n) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current  = 1;
	long long sum      = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous %10 + current %10;
		sum += current;
	}

	return sum %10;

}

long long Fibonaccisumfast(long long n){
	if(n<=1)
		return n;
	long long previous=1;
	long long beforePrevious=0;
	long long current=-1;
	for(long long i=2;i<=n;i++){
		current=(previous+beforePrevious)%10;
	beforePrevious=previous;
	previous=current;
	}
	return current-1;
}

int main() {
	long long n = 0;
	std::cin >> n;
	//    std::cout << fibonacci_sum_naive(n)<<"\n";
	std::cout << Fibonaccisumfast((n+2)%60);
}
