#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	ll n,k;
	cin >> n >> k;
	std::vector<ll> v(n);
	for(int i=0;i<n;i++)
		cin >> v[i];
	ll max_ele = *max_element(v.begin(),v.end());
	ll min_ele = *min_element(v.begin(),v.end());
	if(k==0){
		for(int i=0;i<n;i++)
			cout << v[i] << " ";
		cout << endl;
		return 0;
	}
	if(k&1){
		for(int i=0;i<n;i++){
			cout << max_ele-v[i] << " ";
		}
		cout << endl;
	}else{
		for(int i=0;i<n;i++){
			cout << v[i] - min_ele << " ";
		}
		cout << endl;
	}
	return 0;
}