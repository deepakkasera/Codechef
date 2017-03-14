#include <bits/stdc++.h>
using namespace std;
const int N=1e5+100,K=210,inf=1e9;
int dp[N][K];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t,a,b,k,n,m;
	string s,w;
	cin>>t;
	while(t--){
		cin>>s>>w;
		cin>>a>>b>>k;
		n=s.length();
		m=w.length();
		for(int i=0;i<N;i++){
			for(int j=0;j<K;j++){
				dp[i][j]=inf;
			}
		}
		if(!a){
			cout<<"0\n";
			continue;
		}
		if(!b){
			if(abs(n-m)*a > k)cout<<"-1\n";
			else cout<<abs(n-m)*a<<endl;
			continue;
		}
		dp[0][0]=0;
		b=min(b,2*a);
		for(int i=0;i<m+1;i++){
			for(int j=max(0,i-k);j<=i+k && j<n+1;j++){
				int j1=j%k;
				int j2=(j+1)%k;
				if(i<m+1 && j<n+1 && s[j]==w[i]){
					dp[i+1][j2]=min(dp[i+1][j2],dp[i][j1]);
				}else{
					dp[i+1][j2]=min(dp[i][j1]+b,dp[i+1][j2]);
				}
				dp[i][j2]=min(dp[i][j1]+a,dp[i][j2]);
				dp[i+1][j1]=min(dp[i+1][j1],dp[i][j1]+a);
			}
		}
		int ans=inf;
		for(int j=max(0,m-k);j<=m+k && j<n+1;j++)
			if(j==n) ans=min(ans,dp[m][j%k]);
		if(ans>k) cout<<"-1\n";
		else cout<<ans<<endl;
	}
	return 0;
}