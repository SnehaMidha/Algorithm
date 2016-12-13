#include<iostream>
#include<string>
using namespace std;
bool ispalindrome(const string& str)
{
	int b=str.length();
	if(b==0||b==1)
		return true;
	if(str.at(0)!=str.at(str.length()-1))
		return false;
	return ispalindrome(str.substr(1,str.length()-2));
}
int main()
{
	string a;
	cin>>a;
	if(ispalindrome(a))
		cout<<a<<" is a palindrome\n";
	else
		cout<<a<<" is not a palindrome\n";
return 0;
}
