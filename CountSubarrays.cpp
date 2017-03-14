#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	while(t--){
		cin >> n;
		std::vector<long long> v(n);
		for(int i=0;i<n;i++) cin >> v[i];
		std::vector<long long > dp(n,1);
	    long long count=dp[0];
	    for(int i=1;i<n;i++){
	    	if(v[i]>=v[i-1])
	    		dp[i]+=dp[i-1];
	    	count+=dp[i];
	    }
	    cout<<count<<endl;
	}
	return 0;
}