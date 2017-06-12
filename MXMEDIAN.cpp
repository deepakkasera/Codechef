#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases,n;
	cin >> testCases;
	while(testCases--){
		cin >> n;
		int median;
		std::vector<int> v(2*n+1);
		std::vector<int> v2(n+1);
		for(int i=1;i<=2*n;i++){
			cin >> v[i];
		}
		sort(v.begin(),v.end());
 		for(int i=1;i<=n;i++){
			v2[i] = v[n + i];
			if(i == (n+1)/2) median = v2[i];
		}
		cout << median << endl;
		for(int i=1;i<=n;i++){
			cout << v[i] << " " << v[n + i] << " ";
		}
		cout << endl;
	}
	return 0;
}