#Uses python3
#Task. Compose the largest number out of a set of integers.
import sys

def largest_number(a):
    a.sort(reverse=True)
    print (a)
    res = ""
    for x in a:
        res += x
    return res

if __name__ == '__main__':
    input = sys.stdin.read()
    data = input.split()
    a = data[1:]
    print(a)
    print(largest_number(a))

