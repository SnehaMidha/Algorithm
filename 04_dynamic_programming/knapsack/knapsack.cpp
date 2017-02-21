/*Task. In this problem, you are given a set of bars of gold and your goal is to take as much gold as possible
into your bag. There is just one copy of each bar and for each bar you can either take it or not (hence
you cannot take a fraction of a bar*/

#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {

	int val;
	vector<vector<int> > weight(W+1,vector<int>(w.size()+1,0));
	for(int i=1;i<=w.size();i++)
		for(int wt=1;wt<=W;wt++)
		{
			weight[wt][i]=weight[wt][i-1];
			if(w[i-1]<=wt)
			{
				val= weight[wt - w[i-1]][i-1] + w[i-1];
					if(weight[wt][i] < val)
			  			weight[wt][i] = val;
			}
		}
	return weight[W][w.size()];
}

int main() {
	int n, W;
	std::cin >> W >> n;
	vector<int> w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> w[i];
	}
	std::cout << optimal_weight(W, w) << '\n';
}
