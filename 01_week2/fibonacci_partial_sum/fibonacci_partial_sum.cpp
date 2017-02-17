#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    if (to <= 1)
        return to;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < from - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    long long sum = current;

    for (long long i = 0; i < to - from; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}
int Fibonaccisumfast(long long n){
	if(n<=1)
		return n;
	int previous=1;
	int beforePrevious=0;
	int current=-1;
	n=(n+2)%60;//pisano period for mod 10 is 60 and sumf(n)=f(n+2)-1
	for(int i=2;i<=n;i++){
		current=(previous+beforePrevious)%10;
	beforePrevious=previous;
	previous=current;
	}
	return current-1;
}

int get_fibonacci_partial_sum_fast(long long from, long long to){
	int result;
	int sum1=Fibonaccisumfast(from-1);
int sum2=Fibonaccisumfast(to);
result=(sum2<sum1?sum2+10:sum2)-sum1;
	return result;
}
int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
	std::cout << get_fibonacci_partial_sum_fast(from, to) << '\n';
}
