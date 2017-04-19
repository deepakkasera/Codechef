#include <bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f

using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases,n,k;
	cin >> testCases;
	while(testCases--)
	{
		cin >> n >> k;
		bool flag = false;
		set<int> dishOfLife;
		for(int i=0;i<n;i++)
		{
			int p,num;
			cin >> p;
			for(int j=0;j<p;j++){
				cin >> num;
				dishOfLife.insert(num);
				if(!flag)
				{
					if(dishOfLife.size() == k && i<n-1)
					{
						flag = true;
						cout << "some" << endl;
					}
					if(dishOfLife.size() == k && i == n-1)
					{
						flag = true;
						cout << "all" << endl;
					}
				}
			}
		}
		if(dishOfLife.size() < k) cout << "sad" << endl;
	}
	return 0;
}
