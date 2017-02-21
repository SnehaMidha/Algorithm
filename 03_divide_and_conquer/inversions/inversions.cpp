//Task. The goal in this problem is to count the number of inversions of a given sequence.
#include <iostream>
#include <vector>

using std::vector;


long long merge(vector<int> &a, vector<int> &b, size_t left, size_t right, size_t ave){
	int j=left,k=ave,l=left;
	int number_of_inversions=0;
	while(j<ave && k< right){
		if(a[j]<=a[k])
			b[l++]=a[j++];
		else
		{
			b[l++]=a[k++];
			number_of_inversions+=(ave-j);
			//std::cout<<ave;
		}
	}
	while(j<ave)
		b[l++]=a[j++];
	while(k<right)
		b[l++]=a[k++];
	for(int i=left;i<right;i++)
		a[i]=b[i];
	return number_of_inversions;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	long long number_of_inversions = 0;
	if (right <= left + 1) return number_of_inversions;
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here
	number_of_inversions +=merge(a,b,left, right, ave);
	return number_of_inversions;
}


int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
}
