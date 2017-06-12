#include <bits/stdc++.h>
#define MAXN 32
#define pb push_back
using namespace std;
int main(int argc, char const *argvec[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	long long n,k;
	cin >> n >> k;
	std::vector<long long> vec(n);
	for(int i=0;i<n;i++)
		cin >> vec[i];
	long long x = pow(2,n);
	long long count=0;
	for(int i=1;i<x;i++)
	{
		long double m=1;
		for(int j=0;j<n;j++){
			if(i & (1<<j)){
				m *= vec[j];
			}
		}
		if(m <= k) count++;
	}
	cout << count << endl;
	return 0;
}