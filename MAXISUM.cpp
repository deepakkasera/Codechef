#include <bits/stdc++.h>
#define INF (1LL<<60)
#define ll long long
using namespace std;
ll interaction(ll a[],ll b[],ll n){
	ll sum=0;
	for(int i=0;i<n;i++)
		sum += a[i]*b[i];
	return sum;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,k;
	cin >> t;
	while(t--){
		cin >> n >> k;
		ll a[n],b[n];
		for(int i=0;i<n;i++)
			cin >> a[i];
		for(int i=0;i<n;i++)
			cin >> b[i];
		ll sum1=0,ans=-1*INF,result=0;
		ll sum = interaction(a,b,n);
		for(int i=0;i<n;i++){
			a[i] += k;
			ans = max(ans,sum + k*b[i]);
			a[i] -= (2*k);
			ans = max(ans,sum - k*b[i]);
			a[i]+=k;
		}
		cout << ans << endl;
	}
	return 0;
}