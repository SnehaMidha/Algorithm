# Uses python3
import sys

def optimal_summands(n):
	"""Pairwise Distinct Summands.
	The goal of this problem is to represent a given positive integer n as
	a sum of as many pairwise distinct positive integers as possible.
	Samples:
	>>> optimal_summands(6)
	3
	1 2 3
	>>> optimal_summands(8)
	3
	1 2 5
	"""
	summands = []
	initial=1
	final=n
	while final > 2 * initial :
		summands.append(initial)
		final-=initial
		initial+=1
	
	summands.append(final);
	return summands

if __name__ == '__main__':
    input = sys.stdin.read()
    n = int(input)
    summands = optimal_summands(n)
    print(len(summands))
    for x in summands:
        print(x, end=' ')
