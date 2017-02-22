#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	long long int c,d,l;
	cin >> t;
	while(t--){
		cin >> c >> d >> l;
		long long int minLeg,maxLeg;
		if(c <= 2*d)  minLeg = d*4;
		else if(c > 2*d) minLeg = (d + (c-2*d))*4;
		maxLeg = (c+d)*4;
		//cout << minLeg <<" " << maxLeg << endl;
		if(l>=minLeg && l<=maxLeg && l%4 == 0) cout <<"yes\n";
		else cout << "no\n";
	}
	return 0;
}