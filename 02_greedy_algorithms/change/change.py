# Uses python3
import sys

def get_change(amount):
	"""Changing money optimally.
	The goal in this problem is to find the minimum number of coins needed to
	change the given amount of money using coins with denominations
	1, 5, and 10.
	Samples:
	>>> get_change(2)
	2 # Explanation: 2 = 1 + 1.
	>>> get_change(28)
	6 # Explanation: 28 = 10 + 10 + 5 + 1 + 1 + 1.
	"""
	coins = [10, 5, 1]
	count = 0
	for coin in coins:
        # Update count with the the number of coins 'are held' in the amount.
		count += amount // coin
        # Put remainder to the residuary amount.
		amount %= coin
	return count

if __name__ == '__main__':
    m = int(input())
    print(get_change(m))
