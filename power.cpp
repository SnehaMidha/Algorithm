#include<iostream>
using namespace std;

bool isEven(int n){
	return n%2==0;
}
bool isOdd(int n){
	return !isEven(n);
}
long double power(int x, int n){
	if(x==0||x==1){
		return x;}
	if(n==0)
		return 1;
 long double res;
	if(n<0)
	{
		res=power(x,(-1)*n);
		return 1/res;
	}
	if(isOdd(n))
		return power(x,n-1)*x;
	else
	{
		res=power(x,n/2);
		return res*res;
	}
}
int main(){
	int num,pow;
	cin>>num>>pow;
	cout.setf(ios::fixed,ios::floatfield);
	cout<<power(num,pow);
	return 0;
}
