#include <bits/stdc++.h>
#define ll long long
#define MAX 1000000

using namespace std;
int minPrime[MAX];
int isPrime[MAX];
std::map<int,int>::iterator it;
std::vector<int> res;

bool compare(pair<int,int> &p1,pair<int,int> &p2){
	return p1.second > p2.second;
}

void sieveOfEratosthenes(int n){
	for(int i=0;i<=n;i++)
		isPrime[i] = 1;
	isPrime[0] = isPrime[1] = 0;
	for(int i=2;i<=n;i++){
		if(isPrime[i] == 1){
			for(int j=i*i;j<=n;j+=i)
				isPrime[j]=0;
		}
	}
	return ;
}

std::vector<pair<int,int> > factorizationlog(int n){
	for(int i=0;i<=n;i++)
		minPrime[i] = 0;
	int x = n;
	minPrime[0] = minPrime[1] = 1;
	for(int i=2;i*i<=n;i++){
		if(minPrime[i] == 0){     /// if i is prime
			for(int j=i*i;j<=n;j+=i){
				if(minPrime[j] == 0)
					minPrime[j] = i;
			}
		}
	}

	for(int i=2;i<=n;i++){
		if(minPrime[i] == 0)
			minPrime[i] =  i;
	}
	//std::map<int,int> m;
	std::vector<pair<int,int> > v;
	while(n != 1){
		res.push_back(minPrime[n]);
		m[minPrime[n]]++;
		v[]
		n /= minPrime[n];
	}
	//cout << "minPrime is \n";
	//for(int i=0;i<=x;i++)
	//	cout << minPrime[i] << " ";
	//cout << endl;
	//cout << "map is \n";
	//for(it=m.begin();it!=m.end();it++){
	//	cout << it->first << " " << it->second << endl;
	//}
	//cout << endl;
	//return res;
	return m;
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	//int n = 1000000;
	//factorizationlog(a);
	for(int i=a;i<=b;i++){
		std::map<int,int> m = factorizationlog(i);		
		int ans=1;
		//sort(m.begin(),m.end(),compare);
		for(it=m.begin();it!=m.end();it++){
			cout << it->first << " " << it->second << endl;
		}
	    //cout << endl;
		// while(m.size()!=0){
		// 	int x=1;
		// 	sort(m.begin(),m.end(),compare);
		// 	for(int i=0;i<m.size();i++){
		// 		x *= (m[i]+1); 
		// 	}
		// 	ans += (x);
		// 	m[0] -= 1;
		// 	if(m[0]==0) m.erase(m.begin());
		// }
		for(int i=0;i<m.size();i++){
			ans *= (m[i]+1);
		}
		cout << ans << endl;
	}
	return 0;
}