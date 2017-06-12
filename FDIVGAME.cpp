#include <bits/stdc++.h>
#define ll long long
using namespace std;
// int calculateMex(set< int > s)
// {
// 	int Mex=0;
// 	while(s.find(Mex) != s.end())
// 		Mex++;
// 	return Mex;
// }
ll Grundy(ll n)
{
	if(n==0) return 0;
	else if(n==1) return 1;
	else if(n==2||n==3) return 2;
	else if(n==4||n==5) return 3;
	else return Grundy(n/12);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll t,n,x;
	cin >> t;
	while(t--)
	{
		cin >> n;
		std::vector<ll> v(n);
		for(int i=0;i<n;i++) cin >> v[i];
		ll ans=0;
		for(int i=0;i<n;i++){
			ans^=Grundy(v[i]);
			//cout << calculateGrundy(x) << endl;
		}
		if(!ans)
			cout << "Derek\n";
		else 
			cout << "Henry\n";
	}
	return 0;
}