#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	ll l,r;
	cin >> n >> l >> r;
	std::vector<ll> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(), v.end());
    std::vector< pair<ll,ll> > v1;
    for(int i=0;i<n-1;i++){
    	v1.push_back(make_pair(v[i+1]-v[i]+1,v[i+1]+v[i]-1));
    }
    ll count =0;
    //for(int i=0;i<v1.size();i++) 
    //	cout << v1[i].first << " " <<v1[i].second << endl;
    sort(v1.begin(),v1.end());
    std::vector< pair<ll,ll> > v2;
    v2.push_back(make_pair(v1[0].first,v1[0].second));
    for(int i=1;i<v1.size();i++){
    	if(v1[i].first <= v2[v2.size()-1].second){
    	    v2[v2.size()-1] = make_pair(min(v1[i].first,v2[v2.size()-1].first),max(v1[i].second,v2[v2.size()-1].second));
    	}
    	else v2.push_back(make_pair(v1[i].first,v1[i].second));

    }
    //for(int i=0;i<v2.size();i++) 
    //	cout << v2[i].first << " " <<v2[i].second << endl;
    for(int i=0;i<v2.size();i++){
    	// cout << v2[i].first << " " << v2[i].second << endl;
    	//if(v2[i].first < l) v2[i].first = l;
    	//if(v2[i].second > r) v2[i].second = r;
    	if(v2[i].second < l) continue;
    	if(v2[i].first > r ) continue;
    	if(v2[i].first < l) v2[i].first = l; 
    	if(v2[i].second > r) v2[i].second = r;
    	count += (v2[i].second - v2[i].first +1);
    }
    cout << count << endl;
	return 0;
}