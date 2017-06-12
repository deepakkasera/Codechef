#include <bits/stdc++.h>
using namespace std;
bool isSubsetSum(std::vector<int> &v,int n,int sum)
{
	bool subset[sum+1][n+1];
	for(int i=0;i<=n;i++)
		subset[0][i] = true;
	for(int i=1;i<=sum;i++)
		subset[i][0] = false;
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			subset[i][j] = subset[i][j-1];
			if(i >= v[j-1])
				subset[i][j] = subset[i][j] || subset[i - v[j-1]][j-1];
		}
	}
	return subset[sum][n];
}
int main(int argc, char const *argv[])
{
	int t,n,k;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		std::vector<int> v(n);
		for(int i=0;i<n;i++)
			cin >> v[i];
		if(isSubsetSum(v,n,k)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}