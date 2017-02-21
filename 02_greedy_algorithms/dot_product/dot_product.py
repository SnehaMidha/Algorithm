#Uses python3
#Task. Given two sequences a 1 , a 2 , . . . , a n (a i is the profit per click of the i-th ad) and b 1 , b 2 , . . . , b n (b i is
#the average number of clicks per day of the i-th slot), we need to partition them into n pairs (a i , b j )
#such that the sum of their products is maximized.
import sys

def max_dot_product(a, b):
	a = sorted(a, key=int, reverse = True)
	b = sorted(b, key=int, reverse = True)
	res = 0
	for i in range(len(a)):
		res += a[i] * b[i]
	return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    a = data[1:(n + 1)]
    b = data[(n + 1):]
    print(max_dot_product(a, b))
    
