#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases;
	double l,d,s,c;
	cin >> testCases ;
	while(testCases--){
		cin >> l >> d >> s >> c;
		bool var = (d-1)*log(c+1) >= log(l/s);
		cout << (var ? "ALIVE AND KICKING":"DEAD AND ROTTING") << endl;
	}
	return 0;
}