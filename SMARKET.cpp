#include <bits/stdc++.h>
using namespace std;
std::vector<int>  preprocess(std::vector<int> &v,int n)
{
	std::vector<int> pre(n);
	pre[0] = 1;
	for(int i=1;i<n;i++)
	{
		if(v[i] == v[i-1])
			pre[i] = pre[i-1] + 1;
		else pre[i] = 1;
	}
	return pre;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	int n,q,l,r,k;
	cin >> testCases;
	while(testCases--){
		cin >> n >> q;
		std::vector<int> v(n);
		std::vector<int> pre(n);
		for(int i=0;i<n;i++) cin >> v[i];
		pre = preprocess(v,n);
	}
	return 0;
}