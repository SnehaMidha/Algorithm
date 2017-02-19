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
	//write your code here
/*	for (size_t i = 0; i < segments.size(); ++i) {
		points.push_back(segments[i].start);
		points.push_back(segments[i].end);
	}
*/	sort(segments.begin(),segments.end(),sortend);
	int i=0;
	for(int j=1;j<segments.size();j++)
	{
		points.push_back(segments[i].end);
		while(segments[i].end>=segments[j].start)
			j++;
		i=j;
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
