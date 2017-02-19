#include <iostream>
#include <vector>
#include<algorithm>

using std::vector;

bool srt(const vector<int> & v1, const vector<int> & v2){
	return v1[0]<v2[0];
}
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<vector <int> > seg(starts.size(),vector<int>(2,0));
  for(int i=0;i<starts.size();i++){
	seg[i][0]=starts[i];
	seg[i][1]=ends[i];}
  sort(seg.begin(),seg.end(),srt);
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < seg.size(); j++) {
      cnt[i] += seg[j][0] <= points[i] && points[i] <= seg[j][1];
	if(points[i]<seg[j][0])
		break;
    }
  }
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
