#include <iostream>
#include <vector>

using std::vector;

int edit_distance(vector<int> &str1, vector<int> &str2) {
        //write your code here
        int m=str1.size(),n=str2.size();
        vector <vector <int> > D(m+1,vector<int>(n+1,0));
        /*for(int i=0;i<=m;i++)
                D[i][0]=i;
        for(int j=0;j<=n;j++)
                D[0][j]=j;*/
        int in,del,ma,mm;
        for(int i=1;i<=m;i++)
                for(int j=1;j<=n;j++)
                {
                        in=D[i][j-1];
                        del=D[i-1][j];
                        ma=D[i-1][j-1]+1;
                        mm=D[i-1][j-1];
                        if(str1[i]==str2[j])
                                D[i][j]=std::max(in,std::max(del,ma));
                        else
                                D[i][j]=std::max(in,std::max(del,mm));
                }


        return D[m][n];
}
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
