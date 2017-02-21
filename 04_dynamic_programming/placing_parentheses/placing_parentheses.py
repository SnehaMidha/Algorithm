#Task. Find the maximum value of an arithmetic expression by specifying the order of applying its arithmetic operations using additional parentheses.
# Uses python3
import sys
def evalt(a, b, op):
    if op == '+':
        return a + b
    elif op == '-':
        return a - b
    elif op == '*':
        return a * b
    else:
        assert False

def get_maximum_value(dataset):
    size = len(dataset)
    n = (size+1)//2
    m = [[0 for x in range(n+1)] for y in range(n+1)]
    M = [[0 for x in range(n+1)] for y in range(n+1)]
    for i in range(1,n+1):
        m[i][i]=int(dataset[2*(i-1)])
        M[i][i]=int(dataset[2*(i-1)])
    for s in range(1,n+1):
        for i in range(1,n-s+1):
            j=i+s
            min1=sys.maxsize
            max1=-sys.maxsize-1
            for k in range(1,j):
                a=evalt(M[i][k],M[k+1][j],dataset[2*k-1])
                
                b=evalt(M[i][k],m[k+1][j],dataset[2*k-1])
                
                c=evalt(m[i][k],M[k+1][j],dataset[2*k-1])
                
                d=evalt(m[i][k],m[k+1][j],dataset[2*k-1])
                
                min1=min(min1,min(a,min(b,min(c,d))))
                max1=max(max1,max(a,max(b,max(c,d))))
            m[i][j]=min1
            M[i][j]=max1    
    return M[1][n]


if __name__ == "__main__":
    print(get_maximum_value(input()))
