#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long  t,n,x;
	cin >> t ;
	while(t--){
		cin >> n ;
		long long a[n];
	    long long minimum = INT_MAX;
		for(int i=0;i<n;i++){
			cin >> x;
			minimum = min(minimum,x);
		}
		cout << minimum*(n-1) << endl;
	}
	return 0;
}