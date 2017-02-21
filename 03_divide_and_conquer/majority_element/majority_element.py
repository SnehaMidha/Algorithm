# Uses python3
#Task. The goal in this code problem is to check whether an input sequence contains a majority element

import sys

def get_majority_element(a, left, right):
	if left == right:
		return -1
	if left + 1 == right:
		return a[left]
	mid=left+(right-left)//2
	R=get_majority_element(a, mid, right)
	L=get_majority_element(a, left, mid)
	cl=0
	cr=0
	for i in range(left, right):
		if a[i]==R:
			cr+=1
		if a[i]==L:
			cl+=1

	mid1 = (right-left)//2
	if cl>mid1 or cr >mid1:
		if cl>cr:
			return L	
		else:
			return R
	return -1

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    if get_majority_element(a, 0, n) != -1:
        print(1)
    else:
        print(0)
