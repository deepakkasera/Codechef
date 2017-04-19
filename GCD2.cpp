#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n ;
	int a ;
	string b; 
	cin >> n ;
	while( n-- ){
		cin >> a ;
		cin >> b ;
		if(a == 0){
			cout << b << endl;
			continue ;
		}
		int x=0;
		for(int i = 0 ; b[i] != '\0' ; i++){
			x = (x*10 + b[i]-'0')%a;
		}
		cout << __gcd(a,x) << endl ;
	}
	return 0;
}