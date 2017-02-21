#Task. Given three sequences A = (a 1 , a 2 , . . . , a n ), B = (b 1 , b 2 , . . . , b m ), and C = (c 1 , c 2 , . . . , c l ), find the length of their longest common subsequence, i.e., the largest non-negative integer p such that there exist indices 1 ≤ i 1 < i 2 < · · · < i p ≤ n, 1 ≤ j 1 < j 2 < · · · < j p ≤ m, 1 ≤ k 1 < k 2 < · · · < k p ≤ l such that a i 1 = b j 1 = c k 1 , . . . , a i p = b j p = c k p

#Uses python3

import sys

def lcs3(a, b, c):
    D=[[[0 for k in range(len(c)+1)] for j in range(len(b)+1)] for i in range(len(a)+1)]
    for i in range(1,len(a)+1):
        for j in range(1,len(b)+1):
            for k in range(1,len(c)+1):
                x=D[i-1][j][k]
                y=D[i][j-1][k]
                z=D[i][j][k-1]
                m=D[i-1][j-1][k-1]
                if a[i-1] == b[j-1] and b[j-1] == c[k-1]:
                    D[i][j][k]=m+1         
                else:
                    D[i][j][k]=max(x,max(y,z))
    return D[len(a)][len(b)][len(c)]

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    an = data[0]
    data = data[1:]
    a = data[:an]
    data = data[an:]
    bn = data[0]
    data = data[1:]
    b = data[:bn]
    data = data[bn:]
    cn = data[0]
    data = data[1:]
    c = data[:cn]
    print(lcs3(a, b, c))
