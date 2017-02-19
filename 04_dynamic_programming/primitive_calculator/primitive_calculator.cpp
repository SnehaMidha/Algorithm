#include <iostream>
#include <vector>
#include <algorithm>
#include<limits.h>
using std::vector;

/*vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
  sequence.push_back(n);
  if (n % 3 == 0) {
  n /= 3;
  } else if (n % 2 == 0) {
  n /= 2;
  } else {
  n = n - 1;
  }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
  }*/

vector<int> optimal_sequence(int n) {
	std::vector<int> sequence;
	std::vector<int> c(n+1);
	int val,i;
	c[0]=0,c[1]=0;

	if(n>1) c[2]=1;
	if(n>2) c[3]=1;
	for(i=4;i<=n;i++)
	{
		val=INT_MAX;
		if(i%3==0)
			val=c[i/3];
		if(i%2==0)
			val=val<c[i/2]?val:c[i/2];
			c[i]=(val<c[i-1]?val:c[i-1])+1;
	}
	while (n >= 1) {
		sequence.push_back(n);
		if(n==1||n==2){n=n-1;}
		if(n==3) n=n-2;
			if (n % 3 == 0 && c[n]==c[n/3]+1) {
			n /= 3;
		} else if (n % 2 == 0 &&c[n]==c[n/2]+1) {
			n /= 2;
		} else if(c[n]==c[n-1]+1){
			n = n - 1;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> sequence = optimal_sequence(n);
	std::cout << sequence.size() - 1 << std::endl;
	for (size_t i = 0; i < sequence.size(); ++i) {
		std::cout << sequence[i] << " ";
	}
}
