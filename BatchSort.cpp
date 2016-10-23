#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[25][25];
bool check(){
	for(int i = 1;i<=n;i++){
		int count = 0;
		for(int j = 1; j<=m ; j++){
			if(a[i][j] != j) count++;
			if(count > 2) return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j <= m ; j++){
			cin>>a[i][j];
		}
	}
	if(check())  {cout<<"YES"; return 0;}
    for(int i = 1;i < m ; i++){
    	for(int j = i+1 ; j <= m ; j++){
    		for(int k = 1; k <= n ; k++)  swap(a[k][i],a[k][j]);
    		if(check())  {cout<<"YES"; return 0;}
    	    for(int k = 1; k <= n ; k++)  swap(a[k][i],a[k][j]);
    	}
    }
    cout<<"NO";
	return 0;
}