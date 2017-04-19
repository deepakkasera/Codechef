#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	int n,q,l,r,k;
	cin >> testCases;
	while(testCases--)
	{
		cin >> n >> q;
		std::vector<int> v(n);
		std::vector< pair<int,int> > vp(n);
		for(int i=0;i<n;i++) cin >> v[i];
		while(q--){
			cin >> l >> r >> k;
			l--,r--;
			//std::vector<int> v2(n,0);
			long long cnt=0;
			for(int i=l;i<=r;){
				int j=i,x=1;
				while(v[i] == v[j+1] && j+1<=r)
				{
					j++;
					x++;
				}
				//v2[i]=x;
				i+=x;
				if(x>=k) cnt++;
			}
			// for(int i=0;i<v2.size();i++)
			// {
			// 	if(v2[i] >= k) cnt++;
			// }
			cout << cnt << endl;
		}
	}
	return 0;
}