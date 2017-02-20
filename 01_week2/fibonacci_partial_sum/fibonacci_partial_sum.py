#Task. Given two non-negative integers m and n, where m ≤ n, find the last digit of the sum F m + F m+1 + · · · + F n

# Uses python3
import sys

def fibonacci_partial_sum_naive(from_, to):
    if to <= 1:
        return to

    previous = 0
    current  = 1

    for _ in range(from_ - 1):
        previous, current = current, previous + current

    sum = current

    for _ in range(to - from_):
        previous, current = current, previous + current
        sum += current

    return sum % 10

def Fibonaccisumfast(n):
	if (n<=1):
		return n
	previous = 1
	beforePrevious = 0
	current = -1
	n = (n+2)%60 #pisano period for mod 10 is 60 and sumf(n)=f(n+2)-1
	for _ in range(2, n+1):
		current=(previous+beforePrevious)%10
		beforePrevious=previous
		previous=current
	
	return current-1

def fibonacci_partial_sum_fast(from_, to):
	sum1 = Fibonaccisumfast(from_ - 1)
	sum2 = Fibonaccisumfast(to)
	if sum2 < sum1:
		result = sum2 + 10 - sum1
	else:
		result = sum2 - sum1
	return result

if __name__ == '__main__':
    from_, to = map(int, input().split())
    print(fibonacci_partial_sum_fast(from_, to))
