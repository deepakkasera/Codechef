#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases,n,k;
	cin >> testCases ;
	while(testCases--){
		cin >> n >> k;
		int t,d;
		int ans=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> t >> d;
			if(k > 0){
				int x=k;
				k-=t;
				t-=x;
			}
			if(t >= 0) ans += t*d;
			//cout << ans <<endl;
		}
		cout << ans << endl;
	}
	return 0;
}