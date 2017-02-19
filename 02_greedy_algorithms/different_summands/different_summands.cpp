#include <iostream>
#include <vector>

using namespace std;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int l=1,k=n;
	while(k>2*l)
	{
		summands.push_back(l);
		k=k-l;
		l=l+1;
	}

		summands.push_back(k);
	return summands;
}

int main() {
	int n;
	cin >> n;
	vector<int> summands = optimal_summands(n);
	cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		cout << summands[i] << ' ';
	}
}
