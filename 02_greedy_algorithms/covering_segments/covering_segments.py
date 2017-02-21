# Uses python3
import sys
from collections import namedtuple

Segment = namedtuple('Segment', 'start end')

def optimal_points(segments):
    points = []

    segments.sort(key=lambda s:s.end, reverse=False)
    points.append(segments[0].end)
    j=0
    for i in range(1,len(segments)):   
        while i<len(segments) and points[j]>=segments[i].start :
            i=i+1
           
        if i<len(segments):
            points.append(segments[i].end)
            j=j+1
    return points

if __name__ == '__main__':
    input = sys.stdin.read()
    n, *data = map(int, input.split())
    segments = list(map(lambda x: Segment(x[0], x[1]), zip(data[::2], data[1::2])))

    points = optimal_points(segments)
    print(len(points))
    for p in points:
        print(p, end=' ')
