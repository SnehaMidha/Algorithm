# Uses python3
"""Given an integer n, find the nth Fibonacci number F n .
Sample 1.
	Input:
	3
	Output:
	2
	Explanation:
	F3 = 2.

Sample 2.
	Input:
	10
	Output:
	55
	Explanation:
	F 10 = 55."""

def calc_fib(n):
    if n <= 1:
        return n

    a, b = (0, 1)
    for _ in range(n):
        a, b = b, a + b
    return a

if __name__ == "__main__":
	n = int(input())
	print(calc_fib(n))
