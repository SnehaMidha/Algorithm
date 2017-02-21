# Uses python3
"""You are given a primitive calculator that can perform the following three operations with the current num-
ber x: multiply x by 2, multiply x by 3, or add 1 to x. Your goal is given a positive integer n, find the
minimum number of operations needed to obtain the number n starting from the number 1."""

import sys

def optimal_sequence(n):
	sequence = []
	c=[0 for x in range(n+1)];
	c[0] = c[1] = 0
	if n>1:
		c[2]=1
	if n>2:
		c[3]=1
	for i in range (4, n+1):
		val = sys.maxsize
		if i%3 == 0:
			val = c[i//3]
		if i%2 == 0:
			val = min(val, c[i//2])
		c[i] = min(val, c[i-1]) + 1
	
	while n >= 1:
		sequence.append(n)
		if n==1 or n==2:
			n = n-1
		if n==3:
			n = n-2
		if n % 3 == 0 and c[n]==c[n//3]+1 :
			n = n//3
		elif n % 2 == 0 and c[n]==c[n//2]+1:
			n = n//2;
		elif c[n]==c[n-1]+1 :
			n = n - 1
	return reversed(sequence)

if __name__ == "__main__":
	input = sys.stdin.read()
	n = int(input)
	sequence = list(optimal_sequence(n))
	print(len(sequence) - 1)
	for x in sequence:
		print(x, end=' ')
