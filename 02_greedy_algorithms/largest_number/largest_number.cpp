//Task. Compose the largest number out of a set of integers.
#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isgreaterorequal(string d1,string d2)
{
	string a,b;
	if(d1.length()==d2.length())
	{
		a=d1;
		b=d2;
	}
	else 
	{
		a=d1+d2;
		b=d2+d1;
	}
	int c=a.compare(b);
	return c>=0;
}
string largest_number(vector<string> a) {
	//write your code here
	sort(a.begin(),a.end(),isgreaterorequal);


	std::stringstream ret;
	for (size_t i = 0; i < a.size(); i++) {
		ret << a[i];
	}
	string result;
	ret >> result;
	return result;
}

int main() {
	int n;
	std::cin >> n;
	vector<string> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	std::cout << largest_number(a);
}
