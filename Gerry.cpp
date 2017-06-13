#include <bits/stdc++.h>
using namespace std;
bool function(int *a,int o1,int o2)
{
	int n = o1*o2+o2-1;
	int cummulativeSum[n+1];
	cummulativeSum[0]=0;
	for(int i=1;i<=n;i++){
		cummulativeSum[i] = cummulativeSum[i-1]+a[i-1];
	}
	// cout << "array is \n";
	// for(int i=0;i<n;i++){
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	// cout << "cummulativeSum \n";
	// for(int i=0;i<=n;i++){
	// 	cout << cummulativeSum[i] << " ";
	// }
	// cout << endl;
	for(int i=0;i<o2;i++){
		int result=0;
		for(int j=1;j<o1+1;j++){
			int sum=0;
			sum = cummulativeSum[i+j*o2]-cummulativeSum[i+(j-1)*o2];
			if(sum > o2/2) result++;
		} 
		if(result > o1/2) return true;
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int t,o1,o2,n;
	cin >> t;
	while(t--){
		cin>>o1>>o2;
		n=o1*o2;
		int a[n+o2];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		for(int i=n;i<n+o2-1;i++){
			a[i] = a[i-n];
		}
		if(function(a,o1,o2)) cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}