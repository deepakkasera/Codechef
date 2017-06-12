#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		int n,k,len,x;
		cin >> n >> k;
		std::vector< set<int> > v;
		int count=0;
		for(int i=0;i<n;i++){
			cin >> len;
			set<int> s;
			for(int j=0;j<len;j++){
				cin >> x;
				s.insert(x);
			} 
			v.push_back(s);
			s.clear();
		}
		set<int> sFinal;
		set<int>::iterator it;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				sFinal.insert(v[i].begin(),v[i].end());
				sFinal.insert(v[j].begin(),v[j].end());
				if(sFinal.size() == k) count++;
				sFinal.clear();
			}
		}
		cout << count << endl;
	}
	return 0;
}