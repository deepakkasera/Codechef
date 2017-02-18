#include <bits/stdc++.h>
using namespace std;
// long long int func(std::vector<long long > &v,int l,int r,int k){
// 	//cout << l <<" " << r << endl;
// 	l--;
// 	r--;
// 	std::vector<long long> dp(r-l+1,1);
// 	for(int i=l+1;i<=r;i++){
// 		if(v[i] == v[i-1]) dp[i-l] += dp[i-l-1];
// 		//else dp[i-l] = 1; 
// 	}
//     if( *max_element(dp.begin(),dp.end()) >= k ) {
// 		return v[l+(max_element(dp.begin(),dp.end())-dp.begin())-1];
// 	} 
// 	return -1;
// }
int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	int n,m,l,r,k;
	cin >> n >> m;
	std::vector<int> v(n);
	std::vector<int> dp(n,1);
	std::vector<int> dpr(n,1);
	for(int i=0;i<n;i++) cin >> v[i];
	for(int i=1;i<n;i++){
			if(v[i] == v[i-1]) dp[i]+=dp[i-1];
	}
	for(int i=n-2;i>=0;i--){
		if(v[i] == v[i+1]){
			dpr[i]+=dpr[i+1];
		}
	}
	//for(int i=0;i<n;i++) cout<< dpr[i] << " ";
	int mid;
	while(m--){
		cin >> l >> r >> k;
		bool flag=false;
		--l,--r;
		mid = (r+l)/2;
		if( min( dp[mid] , mid-l+1 ) + min(dpr[mid],r-mid+1) -1 >= k){
			cout << v[mid] << "\n";
			flag = true;
		}  
		if(!flag) cout << "-1\n";
	}
	return 0;
}