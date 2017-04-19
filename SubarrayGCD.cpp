#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int testCases,n;
	cin >> testCases ;
	while(testCases--){
		cin >> n;
		std::vector<int> v(n);
		int gcd;
		for(int i=0;i<n;i++){
			cin >> v[i];
			gcd = ((i==0)?v[i]:__gcd(gcd,v[i]));
		}
		if(gcd == 1){
			cout << n << endl;
		}
		else cout << "-1" << endl;
	}
	return 0;
}