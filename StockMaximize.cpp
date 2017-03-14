#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		std::vector<int> v(n);
		for(int i=0;i<n;i++) cin >> v[i];
		std::vector<int> dp(n);
	    int MIN = INT_MIN;
	    for(int i=n-1;i>=0;i--){
	    	MIN = max(MIN,v[i]);
	    	dp[i]=MIN;
	    }
	    long sum=0;
	    for(int i=0;i<n;i++){
	    	if(dp[i] != v[i])
	    		sum += (dp[i]-v[i]);
	    }
	    cout << sum << endl;
	}
	return 0;
}