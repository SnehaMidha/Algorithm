# Uses python3
"""Task. In this problem, you are given a set of bars of gold and your goal is to take as much gold as possible
into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence
you cannot take a fraction of a bar"""
import sys

def optimal_weight(W, w):
	weight = [[0 for x in range(len(w)+1)] for x in range(W+1)]
	for i in range( len(w)+1 ):
		for wt in range(W + 1):
			weight[wt][i]=weight[wt][i-1]
			if w[i-1]<=wt:
				val= weight[wt - w[i-1] ] [i-1] + w[i-1]
				if weight[wt][i] < val :
			  		weight[wt][i] = val

	return weight[W][len(w)]

if __name__ == '__main__':
    input = sys.stdin.read()
    W, n, *w = list(map(int, input.split()))
    print(optimal_weight(W, w))
