#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

bool sortcol(const vector<double>& v1,const vector<double>& v2)
{
	return v1[2]>v2[2];
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) 
{
	double value = 0.0;
	vector<vector <double> > vbyw(weights.size(),vector<double>(3,0));  
	for(int i=0;i<weights.size();i++)
	{ 
		vbyw[i][0]=weights[i];
		vbyw[i][1]=values[i];
		vbyw[i][2]=(double)values[i]/(double)weights[i];
	}
	sort(vbyw.begin(),vbyw.end(),sortcol);
	double a;
	for(int i=0;i<weights.size();i++)
	{
		if(capacity==0)
			return value;
		a=(vbyw[i][0]>capacity)?capacity:vbyw[i][0];
		value=value+a*vbyw[i][2];
		capacity=capacity-(int)a;
	}
	return value;
}

int main() 
{
	int n;
	int capacity;
	cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);
	for (int i = 0; i < n; i++) 
	{
		cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	cout.precision(10);
	cout << optimal_value << endl;
	return 0;
}
