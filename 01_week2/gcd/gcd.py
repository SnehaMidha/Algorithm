#Task. Given two integers a and b, find their greatest common divisor.
# Uses python3

import sys

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd

def gcd_fast(a, b):
	current_gcd = a
	div = b
	if a==0:
		return b
	if b==0:
		return a
	rem = div % current_gcd
	while rem!=0:
		div = current_gcd
		current_gcd = rem
		rem = div%current_gcd
		
	return current_gcd

if __name__ == "__main__":
    #input = sys.stdin.read()
    a, b = map(int, input().split())
    print(gcd_fast(a, b))
