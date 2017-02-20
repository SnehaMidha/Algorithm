/*Task. Given two integers n and m, output F n mod m (that is, the remainder of F n when divided by m).*/

#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1)
		return n;

	long long previous = 0;
	long long current  = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long getFibonacciHugePisano(long long n,long long m){
	if(n<=1)
		return n;
	long long previous=1;
	long long beforePrevious=0;
	long long current=-1;
	long long a=-1;
	for(long long i=2;i<=n;i++){
		current=(previous+beforePrevious)%m;
		if(previous==0 && current==1){
			long long period=(i+1)-2;
			long long reducedN=n%period;
			return getFibonacciHugePisano(reducedN,m);}
		else{
		beforePrevious=previous;
		previous=current;}
	}
	return current;
}
long long get_pisano_period(long long m) {
    long long a = 0, b = 1, c = a + b;
    for (int i = 0; i < m * m; i++) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0 && b == 1) return i + 1;
    }
}

long long get_fibonacci_huge(long long n, long long m) {
    long long remainder = n % get_pisano_period(m);

    long long first = 0;
    long long second = 1;

    long long res = remainder;

    for (int i = 1; i < remainder; i++) {
        res = (first + second) % m;
        first = second;
        second = res;
    }

    return res % m;
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	std::cout << getFibonacciHugePisano(n, m) << '\n';
}
