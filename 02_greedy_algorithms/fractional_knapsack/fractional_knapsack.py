# Uses python3
import sys
from collections import namedtuple

Item = namedtuple("Item", "value weight")

def get_optimal_value(capacity, weights, values):
	"""Fractional Knapsack.
	Given a set of items and total capacity of a knapsack,
	find the maximal value of fractions of items that fit into the knapsack.
	Samples:
	>>> n = 3; capacity = 50; weights = [60, 100, 120]; values = [20, 50, 30]
	>>> get_optimal_value(capacity, weights, values)
	180.0000
	>>> # Explanation: To achieve the value 180, we take the first item and
	>>> # the third item into the bag.
	>>> n = 1; capacity = 10; weights = [500]; values = [30]
	166.6667
	>>> # Explanation: Here, we just take one third of the only available item.
	"""	
	value = 0.
    
	weight_value_pairs = sorted(
        [Item(v, w) for v, w in zip(values, weights)],
        key=lambda i: i.value / i.weight,
        reverse=True
    )
	print (weight_value_pairs)

	for item in weight_value_pairs:
		if capacity == 0:
			return value
		if item.weight > capacity:
			a = capacity
		else:
			a = item.weight
		value = value + a * item.value/item.weight
		capacity = capacity - int(a)

	return value


if __name__ == "__main__":
    data = list(map(int, sys.stdin.read().split()))
    n, capacity = data[0:2]
    values = data[2:(2 * n + 2):2]
    weights = data[3:(2 * n + 2):2]
    opt_value = get_optimal_value(capacity, weights, values)
    print("{:.10f}".format(opt_value))
