#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int testCases;
	cin >> testCases ;
	while( testCases-- ){
		int n,k;
		string s;
		cin >> n >> k ;
		cin >> s;
		std::vector<int> v;
		int cnt=1;
		for(int i=1;i<n;i++){
			if(s[i] == s[i-1]){
				cnt++;
			}
			else{
				v.push_back(cnt);
				cnt=1;
			}
		}
		v.push_back(cnt);
		int x=0,y=0;
		for(int i=0;i<n;i++){
			x += (s[i]-'0') == i%2;
			y += (s[i] - '0') != i % 2;
		}
		if(min(x,y) <= k){
			cout << 1 << endl;
			continue;
		}
		int left=2,right=n;
	    while(left < right){
			int middle = (left + right) / 2;
			int q=0;
			for(int i : v){
				q += (i - middle) / (middle + 1) + ((i - middle)%(middle+1) > 0);
			}
			if(q > k)
				left = middle + 1;
			else
				right = middle;
		}
		cout << left << endl;
	}
	return 0;
}