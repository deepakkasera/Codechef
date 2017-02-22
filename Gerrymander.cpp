#include <bits/stdc++.h>
using namespace std;
bool func(int o1,int o2,int a[]){
	int n=o1*o2 + o2;
	int cumm[n+1];
	cumm[0]=0;
	for(int i=1;i<=n;i++){
		cumm[i] = cumm[i-1]+a[i-1];
	}
	for(int i=0;i<o2;i++){
		int count=0;
		for(int j=1;j<o1+1;j++){
			int sum=0;
			sum=cumm[(i + j*o2)]-cumm[(i + (j-1)*o2)];
			if(sum > o2/2) count++;
		}
		if(count > o1/2) return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int t,o1,o2,n;
	cin >> t;
	while(t--){
		cin >> o1 >> o2;
		n = o1*o2;
		int a[n+o2];
		for(int i=0;i<n;i++) cin >> a[i];
		for(int i=n;i<n+o2;i++) a[i]=a[i-n]; 
		if(func(o1,o2,a)) cout << "1" << endl;
	    else cout << "0" << endl;
	}
	return 0;
}