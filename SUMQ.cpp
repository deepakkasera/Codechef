#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll vectorSearchLower(ll v[],int start,int end,ll x)
{
	if(start > end)
		return -1;

	if(x >= v[end])
		return end;
	
	int middle = (start + end)/2;
	
	if(middle>0 && v[middle-1] <= x && v[middle] > x)
		return middle-1;

	if(x < v[middle])
		return vectorSearchLower(v,start,middle-1,x);
	else
		return vectorSearchLower(v,middle+1,end,x);
}
ll vectorSearchUpper(ll v[],int start,int end,ll x)
{
	int middle;
	if(x <= v[start])
		return start;
	if(x > v[end])
		return -1;
	
	middle = (start + end)/2;
	
	// if(x == v[middle]) return middle;
	if(v[middle] < x){
		if(middle+1 <= end && x <= v[middle+1])
			return middle+1;
		else 
			vectorSearchUpper(v,middle+1,end,x);
	}
	if(middle-1 >= start && x > v[middle-1])
		return middle;
	else
		vectorSearchUpper(v,start,middle-1,x);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCases;
	cin >> testCases;
	while(testCases--){
		int p,q,r;
		cin >> p >> q >> r;
		ll a[p],b[q],c[r];
		for(ll i=0;i<p;i++)
			cin >> a[i];
		for(ll i=0;i<q;i++)
			cin >> b[i];
		for(ll i=0;i<r;i++)
			cin >> c[i];
		sort(a,a+p);
		sort(b,b+q);
		sort(c,c+r);
		ll prefixSumA[p];
		ll prefixSumC[r];
		ll sum=0;
		for(int i=0;i<p;i++){
			sum = (sum + a[i]%MOD)%MOD;
			prefixSumA[i] = sum;
		}
		sum = 0;
		for(int i=0;i<r;i++){
			sum = (sum + c[i]%MOD)%MOD;
			prefixSumC[i] = sum;
		}
		int start = vectorSearchUpper(b,0,q-1,max(a[0],c[0]));
		ll ans=0;
		if(start == -1){
			cout << "0\n";
			continue;
		}
		for(ll i = start; i < q; i++)
		{
			int x = vectorSearchLower(a,0,p-1,b[i]);
			int y = vectorSearchLower(c,0,r-1,b[i]);
			ll ans1 = prefixSumA[x] + ((x+1)*b[i]%MOD)%MOD;
			ll ans2 = prefixSumC[y] + ((y+1)*b[i]%MOD)%MOD;
			ans += (ans1%MOD*ans2%MOD)%MOD;
		}
		cout << ans%MOD << endl;
	}
	return 0;
}