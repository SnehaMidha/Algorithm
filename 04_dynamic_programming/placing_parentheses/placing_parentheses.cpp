#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <limits.h>
using namespace std;

long long eval(long long a, long long b, char op) {
	if (op == '*') {
		return a * b;
	} else if (op == '+') {
		return a + b;
	} else if (op == '-') {
		return a - b;
	} else {
		assert(0);
	}
}

long long get_maximum_value(const string &exp) {
	//write your code here
	int size=exp.size();
	int n=(size+1)/2;//operands
	vector<vector<int> > m(n+1,vector<int>(n+1,0));
	vector<vector<int> > M(n+1,vector<int>(n+1,0));
	for(int i=1;i<=n;i++)
	{
		m[i][i]=exp[2*(i-1)]-'0';
		M[i][i]=exp[2*(i-1)]-'0';
	}
	for(int s=1;s<n;s++)
	{	for(int i=1;i<=n-s;i++)
		{
			int j=i+s;
			long long min1 = INT_MAX;
			long long max1=INT_MIN;
			for(int k=i;k<j;k++)
			{

				long long a=eval(M[i][k],M[k+1][j],exp[2*k-1]);
				long long b=eval(M[i][k],m[k+1][j],exp[2*k-1]);
				long long c=eval(m[i][k],M[k+1][j],exp[2*k-1]);
				long long d=eval(m[i][k],m[k+1][j],exp[2*k-1]);
				min1=min(min1,min(a,min(b,min(c,d))));
				max1=max(max1,max(a,max(b,max(c,d))));
			}
			m[i][j]=min1;
			M[i][j]=max1;
			
		}
	}
	return M[1][n];
}


int main() {
	string s;
	cin >> s;
	cout << get_maximum_value(s) << '\n';
}
