#include <bits/stdc++.h>
using namespace std;
int test,n,k,var;
string s;
std::multiset< pair<int,int> > dp;
bool comp(pair<int,int> p1, pair<int,int> p2){
	return p1.first/(p1.second+1) > p2.first/(p2.second+1); 
}
void continousFunc(){
	int x=1, flag = 0;
	for(int i=1;i<=n;i++){
		if (i == n && flag)
			dp.push_back(make_pair(x,0));
		if(s[i] == s[i-1]){
			x++;
		}
		else{
			if (i == n - 1)
				flag = 1;
			dp.push_back( make_pair(x,0) );
			x=1;
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>test;
	while(test--){
		cin>>n>>k;
		cin>>s;
		continousFunc();
		for(int i = 1; i <= k; i++){
			sort(dp.begin(),dp.end(),comp);
			dp[0].second += 1;
		}
		sort(dp.begin(), dp.end(), comp);
		cout << dp[0].first / (dp[0].second + 1) << endl;
	}
	return 0;
}