#include <iostream>
#include <string>
#include <vector>
using namespace std;

int edit_distance(const string &str1, const string &str2) {
	//write your code here
	int m=str1.size(),n=str2.size();
	vector <vector <int> > D(m+1,vector<int>(n+1,0));
	for(int i=0;i<=m;i++)
		D[i][0]=i;
	for(int j=0;j<=n;j++)
		D[0][j]=j;
	int in,del,ma,mm;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			in=D[i][j-1]+1;
			del=D[i-1][j]+1;
			ma=D[i-1][j-1];
			mm=D[i-1][j-1]+1;
			if(str1[i-1]==str2[j-1])
				D[i][j]=min(in,min(del,ma));
			else
				D[i][j]=min(in,min(del,mm));
		}


	return D[m][n];
}

int main() {
	string str1;
	string str2;
	cin >> str1 >> str2;
	cout << edit_distance(str1, str2) << endl;
	return 0;
}
