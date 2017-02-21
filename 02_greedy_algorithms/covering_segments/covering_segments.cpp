#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using namespace std;

struct Segment {
	int start, end;
};

bool sortend(const Segment &a,const Segment &b)
{
	return a.end<b.end;
}
vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
        sort(segments.begin(),segments.end(),sortend);
	int j=0;
	points.push_back(segments[0].end);
        for(size_t i=1;i<segments.size();++i){


                while(points[j]>=segments[i].start)
                        ++i;
                if(i<segments.size())
                {
                        points.push_back(segments[i].end);
                        j++;
                }
        }
	return points;
}

int main() {
	int n;
	cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		cout << points[i] << " ";
	}
}
