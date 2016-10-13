#include <bits/stdc++.h>
using namespace std;
int factors(int n,int m,int c){
	int s=sqrt(c);
	int count=0;
	for(int i=1 ; i<=s ; i++){
		if( c%i == 0 && i*i != c) {
           int j=c/i;
           if( i <= n && j <= m) count++;
           if((i <= m && j <= n)) count++;
		}
		if( c%i == 0 && i*i == c){
			if( i <= n && i <= m) count++;
		}
	}
	return count;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
	    int n,m,c;
	    cin>>n>>m>>c;
	    cout<<factors(n,m,c)<<"\n";
	}
	return 0;
}
