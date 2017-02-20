# Task. Given an integer n, find the last digit of the sum F 0 + F 1 + · · · + F n .
# Uses python3
import sys

def fibonacci_sum_naive(n):
    if n <= 1:
        return n

    previous = 0
    current  = 1
    sum      = 1

    for _ in range(n - 1):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def Fibonaccisumfast(n):
	n = (n+2)%60	
	if n<=1:
		return n
	previous=1
	beforePrevious=0
	current=-1
	for _ in range(2, n+1):
		current = (previous+beforePrevious)%10
		beforePrevious = previous
		previous = current
	return current-1


if __name__ == '__main__':
    #input = sys.stdin.read()
    n = int(input())
    print(fibonacci_sum_naive(n))
