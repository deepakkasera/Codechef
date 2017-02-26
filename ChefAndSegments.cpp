#include <bits/stdc++.h>
using namespace std;
std::vector<int> sieve(int n){
	bool isPrime[n+1];
	for(int i=0;i<=n;i++)isPrime[i]=true;
	isPrime[0]=false;
	isPrime[1]=false;
	for(int i=2;i*i<=n;i++){
		if(isPrime[i]){
			for(int p=2*i;p<=n;p+=i)
				isPrime[p]=false;
		}
	}
	std::vector<int> v;
	for(int i=2;i<=n;i++){
		if(isPrime[i]) v.push_back(i);
	}
	return v;
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	std::vector<int> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	std::vector<int> prime = sieve(n);
	int cumm[101][25];
	for(int i=1;i<=100;i++){
		int temp=i;
		//count=0;
		for(int p=0;p<25;p++){
			int count=0;
			while(temp>0 && temp % prime[p] == 0){
				count++;
				temp/=prime[p];
			}
			cumm[i][p] = count;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<prime.size();j++){
			
		}
	}
    //prime = sieve(100);
	//int t,l,r,m;
    // cin >> t;
    // while(t--){
    // 	cin >> l >> r >> m;
    // 	l--,r--;
    // 	cout << ans(v,l,r,m) << endl;
    // }
	return 0;
}