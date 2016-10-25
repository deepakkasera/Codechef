#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)  cin>>a[i];
    int i=0;
    while(i<n){
        if(a[i]%2 == 0) a[i] = 0;
        else if( a[i+1] >= 1) {
            a[i+1]--;
        }
        else {
        	cout<<"NO";
        	return 0;
        }
        i++;
    }
    if(a[n-1] == 0) { cout<<"YES"; return 0;}
    cout<<"NO";
	return 0;
}