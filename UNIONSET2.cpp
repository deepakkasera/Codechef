#include <bits/stdc++.h>
#define MOD 1000000007
#define MAXN 2503
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;
	while(testCases--)
	{
		std::vector<set<int> > vecSet;
		std::vector<int> vec[10007];
		bool isVisible[10007] = {false};
		int n,k,len[10007],x;
		int var1=0,var2=0;
		int result=0;
		cin >> n >> k;
		for(int i=1;i<=n;i++){
			cin >> len[i];
			for(int j=1;j<=len[i];j++){
				cin >> x;
				vec[i].push_back(x);
			}
		}
		for (int i = 1; i <= n; ++i)
		{
			/* code */
			for(int j=1;j<=k;j++)
				isVisible[j] = false;
			for(int j=0;j<vec[i].size();j++){
				isVisible[vec[i][j]]=true;
			}
			var1 = len[i];
			for(int j=i+1;j<=n;j++){
				var2 = 0;
				for(int y=0;y<vec[j].size();y++){
					if(!isVisible[vec[j][y]])
						var2++;
				}
				if(var1 + var2 == k)
					result++;
			}
		}
		cout << result << endl;
		for(int i=0;i<=n;i++){
			vec[i].clear();
		}
	}
	return 0;
}