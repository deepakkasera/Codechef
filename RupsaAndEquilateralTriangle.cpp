#include <bits/stdc++.h>
#define MAXN 5000010
using namespace std;
bool isPrime[MAXN];
bool isHypo[MAXN];
std::vector<int> primes;
bool isPerfectSquare(int x){
	int sqrtX = sqrt(x);
	return sqrtX*sqrtX == x;
}
void sieve()
{
	memset(isPrime,true,sizeof(isPrime));
	memset(isHypo,false,sizeof(isHypo));
	isPrime[0] = isPrime[1] = false;
	for(int i=2;i*i<MAXN;i++){
		if(isPrime[i]){
			for(int j=i*i;j<MAXN;j+=i)
				isPrime[j] = false;
		}
	}
	for(int i=2;i<MAXN;i++){
		if(isPrime[i] && i%4==1){
			primes.push_back(i);
		}
	}
	for(int i=0;i<primes.size();i++){
		int primeNumber = primes[i];
		for(int j=primeNumber;j<MAXN;j+=primeNumber)
			isHypo[j] = true;
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n;
	cin>>t;
	sieve();
	while(t--){
		cin >> n;
		// bool flag = false;
		// for(int i=2;i<2*n;i+=2){
		// 	if(isPerfectSquare(n*n - (i*i)/4)){
		// 		cout << "YES\n";
		// 		flag=true;
		// 		break;
		// 	}
		// }
		// if(!flag) cout << "NO\n";
		if(isHypo[n]) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}