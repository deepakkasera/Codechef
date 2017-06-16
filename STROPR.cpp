#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
int main(int argc, char const *argv[])
{
	ll t,n,x,m;
	cin>>t;
	while(t--){
		cin >> n >> x >> m;
		ll a[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		x-=1;
		if(x <= 1){
			if(x==0){
				cout << a[0]%MOD << endl;
			}else{
				cout << (((a[0]%MOD)*(m%MOD))%MOD + a[1]%MOD)%MOD << endl;
			}
			continue;
		}
		for(int i=1;i<=m;i++){
			for(int i=1;i<n;i++){
				a[i] = (a[i]%MOD + a[i-1]%MOD)%MOD;
			}
		}
		cout << a[x] << endl;
	}
	return 0;
}