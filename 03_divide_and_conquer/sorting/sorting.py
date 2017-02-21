# Uses python3
"""Task. To force the given implementation of the quick sort algorithm to efficiently process sequences with
few unique elements, your goal is replace a 2-way partition with a 3-way partition. That is, your new
partition procedure should partition the array into three parts: < x part, = x part, and > x part."""

import sys
import random

m1 = 0
m2 = 0

def partition2(a, l, r):
    x = a[l]
    j = l;
    for i in range(l + 1, r + 1):
        if a[i] <= x:
            j += 1
            a[i], a[j] = a[j], a[i]
    a[l], a[j] = a[j], a[l]
    return j

def partition3(a, l, r):
	global m1, m2
	x = a[l]
	i = l+1
	while i <= m2:
		if a[i] < x: 
			a[i], a[m1] = a[m1], a[i]
			m1+=1
			i+=1
		elif a[i]>x :
			a[i], a[m2] = a[m2], a[i]
			m2-=1
		else:
			i+=1

def randomized_quick_sort3(a, l, r):
	if l >= r:
		return

	k = random.randint(l,r)
	a[l], a[k] = a[k], a[l]
	global m1, m2
	m1 = l
	m2 = r
	partition3(a, l, r)

	randomized_quick_sort3(a, l, m1 - 1)
	randomized_quick_sort3(a, m2 + 1, r)


def randomized_quick_sort(a, l, r):
    if l >= r:
        return
    k = random.randint(l, r)
    a[l], a[k] = a[k], a[l]
    m = partition2(a, l, r)
    randomized_quick_sort(a, l, m - 1);
    randomized_quick_sort(a, m + 1, r);


if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    randomized_quick_sort3(a, 0, n - 1)
    for x in a:
        print(x, end=' ')
