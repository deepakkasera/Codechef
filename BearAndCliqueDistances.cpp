#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;

typedef pair<ll,ll> myPair;

ll pathLength[100050];
ll visited[100050];
ll state[100050];

std::vector<myPair> v[100050];

struct myComparator
{
	bool operator() (const myPair &x,const myPair &y)
	{
		return x.second > y.second;
	}
	
};

priority_queue<myPair , std::vector<myPair> , myComparator> pq;
void dijkstraAlgo(ll n,ll s,ll k,ll x)
{
	ll tp,dist,u;
	for(ll i=1;i<=n;i++)
	{
		pathLength[i] = 1e18;
		visited[i] = 0;
		state[i] = 0;
	}
	pathLength[s] = 0;
	pq.push(make_pair(s,0));
	while(!pq.empty())
	{
		tp = pq.top().first;
		pq.pop();
		state[tp] = 1;
		if(tp <= k && visited[tp]==0)
		{
			for(ll i=1;i<=k && visited[i] == 0;i++){
				if(state[i] == 0 && pathLength[i] > pathLength[tp] + x){
					pathLength[i] = pathLength[tp] + x;
					visited[i] = 1;
					pq.push(make_pair(i,pathLength[i]));
				}
			}
		}
		for(ll i=0;i<v[tp].size();i++){
			u = v[tp][i].first;
			dist = v[tp][i].second;
			if(state[u] == 0 && pathLength[u] > pathLength[tp] + dist){
				pathLength[u] = pathLength[tp] + dist;
				pq.push(make_pair(u,pathLength[u]));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll testCases,n,k,x,m,s,a,b,c;
	cin >> testCases;
	while(testCases--){
		cin >> n >> k >> x >> m >> s;
		for(ll i=0;i<m;i++){
			cin >> a >> b >> c;
			v[a].push_back(make_pair(b,c));
			v[b].push_back(make_pair(a,c));
		}
		dijkstraAlgo(n,s,k,x);
		for(ll i=1;i<=n;i++)
		{
			cout << pathLength[i] << " ";
		}
		cout << endl;
		for(int i=1;i<=n;i++){
			v[i].clear();
		}
	}
	return 0;
}