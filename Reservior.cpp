#include <bits/stdc++.h>
using namespace std;
char s[1005][1005];
int main(int argc, char const *argv[])
{
	int testCases;
	cin>>testCases;
	while(testCases--){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>s[i]+1;
		}
		bool ret = true;
		for(int i=1;i<=n && ret;i++){
			for(int j=1;j<=m && ret;j++){
				if(s[i][j]=='B'){
					if(i+1<=n && s[i+1][j]!='B') ret=false;
				}
				else if (s[i][j]=='W'){
					if(j==1||j==m||s[i][j-1]=='A'||s[i][j+1]=='A') ret=false;
				}
			}
		}
		cout << ((ret) ? "yes\n":"no\n");
	}
	return 0;
}