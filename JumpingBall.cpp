#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans = 0;
	for(int i=0 ; s[i]=='<' ; i++) ans++;
	for(int i=n-1 ; s[i]=='>' ; i--)   ans++;
	cout<<ans;
	return 0;
}