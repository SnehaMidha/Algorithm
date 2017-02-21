#Task. The goal in this problem is to count the number of inversions of a given sequence.
# Uses python3
import sys
def merge(a,b,left,right,ave):
    j=left
    k=ave
    l=left
    number_of_inversions=0
    while j<ave and k<right:
        if a[j]<=a[k]:
            b[l]=a[j]
            l+=1
            j+=1
        else:
            b[l]=a[k]
            l+=1
            k+=1
            number_of_inversions+=(ave-j)
    while j<ave:
        b[l]=a[j]
        l+=1
        j+=1
    while k<right:
        b[l]=a[k]
        l+=1
        k+=1
    for i in range(left,right):
        a[i]=b[i]
    return number_of_inversions

def get_number_of_inversions(a, b, left, right):
    number_of_inversions = 0
    if right - left <= 1:
        return number_of_inversions
    ave = left+(right-left) // 2
    number_of_inversions += get_number_of_inversions(a, b, left, ave)
    number_of_inversions += get_number_of_inversions(a, b, ave, right)
    number_of_inversions +=merge(a,b,left, right, ave);
    return number_of_inversions

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *a = list(map(int, input.split()))
    b = n * [0]
    print(get_number_of_inversions(a, b, 0, len(a)))
