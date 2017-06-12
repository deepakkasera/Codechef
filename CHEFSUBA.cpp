#include <bits/stdc++.h>
// #define pb push_back
using namespace std;
std::vector<int> v;
std::vector<int> sum;
void rotate(std::vector<int> &v,int n)
{
	int x = v[n-1];
	for(int i=n-1;i>0;i--){
		v[i] = v[i-1];
	}
	v[0] = x;
}
void sumfun(std::vector<int> &vec,int n,int k){
	int count=0;
	for(int i=0;i<k;i++){
		count += vec[i];
	}
	sum.push_back(count);
	for(int i=k;i<2*n;i++){
		count += (vec[i] - vec[i-k]);
		sum.push_back(count);
	}
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,k,p;
	cin >> n >> k >> p;
	v.resize(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}
	if(k > n) k = n;
	string s;
	cin >> s;
	std::vector<int> vec(2*n);
	for(int i=0;i<2*n;i++){
		vec[i]=v[i];
		if(i >= n) vec[i]=v[i-n];
	}
	sumfun(vec,n,k);
	int x=n-k+1;
	k=x;
	deque<int> q;
	for(int i=0;i<x;i++){
		while(!q.empty() && sum[i] >= sum[q.back()])
			q.pop_back();
		q.push_back(i);
	}
	std::vector<int> result;
	for(int i=k;i<sum.size();i++){
		result.push_back(sum[q.front()]);
		while(!q.empty() && q.front() <= i-k)
            q.pop_front();
		while(!q.empty() && sum[i] >= sum[q.back()])
			q.pop_back();
        q.push_back(i); 
	}
	result.push_back(sum[q.front()]);
	result.erase(result.begin());
	reverse(result.begin(),result.end());
	int count=0;
	for(int i=0;i<p;i++){
		if(s[i] == '!') count = (count+1)%n;
		else cout << result[count] << endl;
	}
	return 0;
}