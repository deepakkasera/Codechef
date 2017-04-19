#include <bits/stdc++.h>
//#define int long long
using namespace std;
 
int main(int argc, char const *argv[])
{
	int t,l,r;
	cin>>t;
	std::vector<int> v(10);
	while(t--){
		cin>>l>>r;
		int s=0;
		for(int i=0;i<10;i++){
			cin >> v[i];
			s += v[i]; 
		}
		std::vector< std::vector<int>  > d(r-l+1,std::vector<int>(10));
		int ans=0;
		// if(s == 0){
		// 	for(int i=l;i<=r;i++){
		// 		int num=i,z=0;
		// 		while(num){
		// 			if(num%10==0) z++;
		// 			num/=10;
		// 		}
		// 		if(num==i-l) ans++;
		// 	}
		// 	cout << ans << endl;
		// }
		//if(s!=0){
			for(int i=l;i<=r;i++){
			//cout << "hello\n";
			int x = i;
			while(x){
				d[i-l][x%10]++;
				x/=10;
			}
		}
		int x=0;
		for(int i=l;i<=r;i++){
			bool var=false;
			for(int j=0;j<10;j++){
				if(d[i-l][j] == v[j]){
					var = true;
				}
			}
			if(!var) x++;
		}
		cout << x << endl;
		// }
	}
	return 0;
} 