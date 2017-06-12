#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ll testCases;
	cin >> testCases;
	while(testCases--){
		ll u,v;
		cin >> u >> v;
		if(u==0 && v==0){
			cout << "1\n";
		}
		else if(v==0){
			cout << (u+1)*(u+2)/2 << endl;
			continue;
		}
		else if(u==0){
			cout << v*(v+1)/2 + 1 << endl;
			//continue;
		}
		else{
			//ll variable=u;
		    ll ans = (v+u)*(v+1+u)/2 + 1;
		    ans += u;
		    cout << ans << endl;
		}
	}
	return 0;
}