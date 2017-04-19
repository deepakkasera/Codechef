#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases,n;
	ll m;
	cin >> testCases ;
	while(testCases--){
		cin >> n >> m ;
		std::vector<ll> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
		} 
		sort(v.rbegin(),v.rend());
		int i=0;
		ll sum=0;
		while(sum < m && i<n){
			sum += v[i];
			i++;
		}
		cout << ((sum>=m) ? i : -1) << endl;
	}
	return 0;
}