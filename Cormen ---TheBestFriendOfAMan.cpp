#include <bits/stdc++.h>
using namespace std;
int a[501];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k>>a[0];
    int z=0;
    for(int i=1;i<n;i++){
      cin>>a[i];
      z+=max(0,k-a[i]-a[i-1]);
      a[i]+=max(0,k-a[i]-a[i-1]);
    }
    cout<<z<<"\n";
    for(int i=0;i<n;i++)  cout<<a[i]<<" ";
	return 0;
}