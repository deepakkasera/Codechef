#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	long long n;
	char c;
	cin>>n>>c;
	long long int ans=0;
	int seat[] = {4,5,6,3,2,1};
	ans+=seat[c-'a'];
	ans+=((n-1)/4)*16;
    if(n%2 == 0)  ans+=7;	
    cout<<ans;
	return 0;
}