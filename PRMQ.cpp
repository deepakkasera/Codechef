#include <bits/stdc++.h>
#define MAXN 1000010
#define ll long long
using namespace std;
int isPrimeNumber[1000005];
int minPrime[1000005];
void minPrimeFun(){
	for(int i=0;i<=1000000;i++)
		minPrime[i] = 0;
	minPrime[0] = minPrime[1] = 1;
	for(int i=2;i*i<=1000000;i++){
		if(minPrime[i] == 0){     /// if i is prime
			for(int j=i*i;j<=1000000;j+=i){
				if(minPrime[j] == 0)
					minPrime[j] = i;
			}
		}
	}
	for(int i=2;i<=1000000;i++){
		if(minPrime[i] == 0)
			minPrime[i] =  i;
	}
}
std::vector<int> factorizationlog(map<int,int> &m,int n){
	std::vector<int> res;
	while(n != 1){
		res.push_back(minPrime[n]);
		m[minPrime[n]]++;
		n /= minPrime[n];
	}
	return res;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	std::vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		/* code */
		cin >> vec[i];
	}
	int queries,l,r,x,y;
	cin >> queries;
	int var,exp;
	minPrimeFun();
	std::vector<int> primeNumbers;
	map<int,int> mPrime;
	while(queries--){
		cin >> l >> r >> x >> y;
		ll result=0;
		l--,r--;
		for(int i=x;i<=y;i++){
				if(minPrime[i] == i){
					for(int j=l;j<=r;j++){
						var = vec[j];
					    exp = 0;
					    primeNumbers = factorizationlog(mPrime,var);
					    // cout << "var value " << var << endl;
					    // while(var%i==0){
					    //    exp += 1;
						//    var /= i;
						// }
						if(var%i==0){
							result += mPrime[i];
						}
						mPrime.clear();
						primeNumbers.clear();
						// cout << "exp value " << exp << "\n";
						// result += exp;
					}
				}
		    }
		cout << result << endl;
	}
	return 0;
}