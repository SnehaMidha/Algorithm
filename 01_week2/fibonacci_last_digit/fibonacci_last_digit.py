#Task. Given an integer n, find the last digit of the nth Fibonacci number F n (that is, F n mod 10).

# Uses python3
import sys

def get_fibonacci_last_digit_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1

    for _ in range(n - 1):
        previous, current = current, previous + current

    return current % 10

def get_fibonacci_last_digit_fast(n):
	if n<=1:
		return n
		
	previous = 0
	current  = 1

	for _ in range(n-1):
		previous, current =  current, (previous + current)%10

	return current

if __name__ == '__main__':
    #input = sys.stdin.read()
    n = int(input())
    #print(get_fibonacci_last_digit_naive(n))
    print(get_fibonacci_last_digit_fast(n))
