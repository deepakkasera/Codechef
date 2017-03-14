#include <bits/stdc++.h>
using namespace std;
int prefix[1000005];
void prefixTable(string a,int n){
	int i=1,j=0;
	prefix[0]=0;
	while(i<n){
		if(a[i] == a[j]){
			prefix[i]=j+1;
			i++;
			j++;
		}
		else{
			if(j>0) j=prefix[j-1];
			else if (j==0) prefix[i]=0,i++;
		}
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	string a,b;
	cin>>n;
	cin>>a>>b;
	b+=b;
	prefixTable(a,n);
	int i=0,j=0,k=0,m=0,r=0;
	while(i < 2*n){
		if(b[i] == a[j]){
			i++;j++;k++;
		}
		else if (b[i] != a[j]){
			k=0;
			if(j!=0) j=prefix[j-1];
			else i++;
		}
		if(j == n) break;
		if(k > m){
			m=k;
			r=i-j;
		}
	}
	cout<<r<<endl;
	return 0;
}