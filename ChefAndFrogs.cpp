#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int,int> const &p1,pair<int,int> const &p2){
	return p1.second > p2.second ;
}
int main(int argc, char const *argv[])
{
	int n,k,p,a,b;
	cin >> n >> k >> p;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	std::vector< pair<int,int> > v1(n);
    for(int i=0;i<n;i++){
    	v1[i] = make_pair(i,v[i]);
    }
    sort(v1.begin(),v1.end(),comp);
    std::vector<int> dp(n);
    dp[v1[0].first] = v1[0].second+k;
    for(int i=1;i<n;i++){
    	if(v1[i-1].second - v1[i].second <= k)
    		dp[v1[i].first] = dp[v1[i-1].first];
    	else dp[v1[i].first] = v1[i].second+k;
    }
    //for(int i=0;i<n;i++) cout << dp[i] << " ";
    while(p--){
    	cin >> a >> b;
    	a--,b--;
    	if(dp[a] == dp[b]) cout << "Yes\n";
    	else cout << "No\n";
    }
    return 0;
}