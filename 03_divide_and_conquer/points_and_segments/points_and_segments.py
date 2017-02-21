# Task. You are given a set of points on a line and a set of segments on a line. The goal is to compute, for each point, the number of segments that contain this point.
# Uses python3
import sys

def fast_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    seg= [list(x) for x in zip(starts, ends)]  
    seg.sort(reverse=False)
    for i in range(len(points)):
        for j in rane(len(starts)):
            cnt[i] += seg[j][0]<=points[i] and points[i]<=seg[j][1]
            if points[i]<seg[j][0]:
                break
    return cnt

def naive_count_segments(starts, ends, points):
    cnt = [0] * len(points)
    for i in range(len(points)):
        for j in range(len(starts)):
            if starts[j] <= points[i] <= ends[j]:
                cnt[i] += 1
    return cnt

if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    starts = data[2:2 * n + 2:2]
    ends   = data[3:2 * n + 2:2]
    points = data[2 * n + 2:]
    #use fast_count_segments
    cnt = naive_count_segments(starts, ends, points)
    for x in cnt:
        print(x, end=' ')

