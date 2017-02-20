# Uses python3
import sys

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

def lcm_naive(a, b):
    for l in range(1, a*b + 1):
        if l % a == 0 and l % b == 0:
            return l

    return a*b

def lcm_fast(a, b):
	return (a * b)//gcd_fast(a, b)

if __name__ == '__main__':
    #input = sys.stdin.read()
    a, b = map(int, input().split())
    print(lcm_fast(a, b))

