#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCases,n,a;
	cin>>testCases;
	while(testCases--){
		cin >> n;
		int cnt=0,bandwidth=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin >> a;
				cnt+=a;
			}
		}
		if(cnt>=n){
			bandwidth=0;
			cnt = cnt-n;
		}
		int var=n-1;
		while(cnt>0 && var>=1){
			bandwidth++;
			cnt = cnt-2*var;
			var--;
		}
		cout<<bandwidth<<endl;
	}
	return 0;
}