#include <bits/stdc++.h>
#define MAXN 1000000+5
#define ll long long
using namespace std;
int minPrime[MAXN];
void minPrimeFun(){
	minPrime[1] = 1;
	for(int i=2;i<MAXN;i++){
		minPrime[i]=i;
	}
	for(int i=4;i<MAXN;i+=2)
		minPrime[i]=2;
	for(int i=3;i*i<MAXN;i++){
		if(minPrime[i] == i){
			for(int j=i*i;j<MAXN;j+=i){
				if(minPrime[j] == j)
					minPrime[j]=i;
			}
		}
	}
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
	minPrimeFun();
	int queries,l,r,x,y;
	cin >> queries;
	while(queries--){
		cin >> l >> r >> x >> y;
		l--,r--;
		ll result=0;
		for(int i=l;i<=r;i++){
			ll num = vec[i];
			while(num != 1){
				if(minPrime[num]>=x && minPrime[num]<=y)
					result++;
				num /= minPrime[num];
			}
		}
		cout << result << endl;
	}
	return 0;
} 