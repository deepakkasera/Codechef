#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin >> t;
	std::vector<int> x(n);
	std::vector<int> y(n);
	while(t--){
		cin >> n;
		for(int i=0;i<n;i++) cin>>x[i];
		for(int i=0;i<n;i++) cin>>y[i];
		ll ans1=x[0];
	    ll ans2=y[0];
	    for(int i=1;i<n;i++){
	    	if(i%2==0)ans1+=x[i];
	    	else ans1+=y[i];
	    }
	    for(int i=1;i<n;i++){
	    	if(i%2==0)ans2+=y[i];
	    	else ans2+=x[i];
	    }
	    cout << min(ans2,ans1)<<endl;
	}
	return 0;
}