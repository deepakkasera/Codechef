#include <bits/stdc++.h>
using namespace std;
std::vector<int> v[100010];
int main(int argc, char const *argv[])
{
	int n,e,a,b;
	cin>>n>>e;
	for(int i=0;i<e;i++){
		cin >> a >> b ;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		if(v[i].size()%2 != 0){
			cout << "NO\n";
			return 0;
		}
	}
	return 0;
}