#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		long double s,v;
		cin>>s>>v;
		long double ans=(2*s)/(3*v);  
		cout<<setprecision(10)<<fixed<<ans<<"\n";
	}
	return 0;
}
