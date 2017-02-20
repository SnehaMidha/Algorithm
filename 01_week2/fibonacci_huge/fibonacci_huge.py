#Task. Given two integers n and m, output F n mod m (that is, the remainder of F n when divided by m).
# Uses python3

import sys

def get_fibonacci_huge_naive(n, m):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % m
    
def getFibonacciHugePisano(n, m):
	if(n<=1):
		return n
	previous=1
	beforePrevious=0
	current=-1
	a=-1
	for i in range(2,n+1):
		current=(previous+beforePrevious)%m
		if previous==0 and current==1:
			period = (i+1)-2
			reducedN = n%period
			return getFibonacciHugePisano(reducedN,m)
		else:
			beforePrevious=previous
			previous=current
	return current

if __name__ == '__main__':
    n, m = map(int, input().split())
    print(getFibonacciHugePisano(n, m))
