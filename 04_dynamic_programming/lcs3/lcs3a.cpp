//Task. Given three sequences A = (a 1 , a 2 , . . . , a n ), B = (b 1 , b 2 , . . . , b m ), and C = (c 1 , c 2 , . . . , c l ), find the length of their longest common subsequence, i.e., the largest non-negative integer p such that there exist indices 1 ≤ i 1 < i 2 < · · · < i p ≤ n, 1 ≤ j 1 < j 2 < · · · < j p ≤ m, 1 ≤ k 1 < k 2 < · · · < k p ≤ l such that a i 1 = b j 1 = c k 1 , . . . , a i p = b j p = c k p

#include <iostream>
#include <vector>

using std::vector;


int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
	vector<vector<vector<int> > > D(a.size()+1,vector<vector<int> >(b.size()+1,vector<int>(c.size()+1,0)));
	int x,y,z,m;
	for(int i=1;i<=a.size();i++)
		for(int j=1;j<=b.size();j++)
			for(int k=1;k<=c.size();k++)
			{
				x=D[i-1][j][k];
				y=D[i][j-1][k];
				z=D[i][j][k-1];
				m=D[i-1][j-1][k-1];
				if(a[i-1]==b[j-1] && b[j-1]==c[k-1])
				{D[i][j][k]=m+1;
					std::cout<<a[i-1]<<std::endl;}
				else
					D[i][j][k]=std::max(x,std::max(y,z));

			}

	return D[a.size()][b.size()][c.size()];
}

int main() {
	size_t an;
	std::cin >> an;
	vector<int> a(an);
	for (size_t i = 0; i < an; i++) {
		std::cin >> a[i];
	}
	size_t bn;
	std::cin >> bn;
	vector<int> b(bn);
	for (size_t i = 0; i < bn; i++) {
		std::cin >> b[i];
	}
	size_t cn;
	std::cin >> cn;
	vector<int> c(cn);
	for (size_t i = 0; i < cn; i++) {
		std::cin >> c[i];
	}
	std::cout << lcs3(a, b, c) << std::endl;
	//	std::cout<<edit_distance(a,b);


}
