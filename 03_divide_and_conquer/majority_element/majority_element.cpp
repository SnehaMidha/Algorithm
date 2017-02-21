/*Task. The goal in this code problem is to check whether an input sequence contains a majority element*/

#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  
  int mid=left+(right-left)/2;
  int R=get_majority_element(a,mid,right);
  int L=get_majority_element(a,left,mid);
	std::cout<<R<<" "<<L<<"\n";
  int cl=0,cr=0;
  for(int i=left;i<right;i++)
	{
	  if(a[i]==R) cr++;
	  if(a[i]==L) cl++;
	}
int mid1=(right-left)/2;
 if(cl>mid1 || cr >mid1)
	return (cl>cr)?L:R;
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
