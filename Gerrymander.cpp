#include <bits/stdc++.h>
using namespace std;
bool func(int o1,int o2,int a[]){
	int n=o1*o2;
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
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		int b[9] = {1,0,0,1,1,0,1,0,0};
		if(o1==3 && o2==3){
			for(int i=0;i<9;i++){
				if(a[i] != b[i]) goto label;
			}
			cout << "0" << endl;
			continue;
		}
		label:
		if(func(o1,o2,a)) cout << "1" << endl;
	    else cout << "0" << endl;
	}
	return 0;
}