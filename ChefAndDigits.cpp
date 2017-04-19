#include <bits/stdc++.h>
#define lli long long int
#define ll long long
#define INF 0x3f3f3f3f
#define pair<int,int> myPair
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli testCases,l,r;
	cin >> testCases;
	std::vector<lli> v(10);
	
	while(testCases--)
	{
		cin >> l >> r;
		for(lli i=0;i<10;i++)
			cin >> v[i];
		std::vector< std::vector<lli>  > digitsCount(r-l+1,std::vector<lli>(10));
		for(lli i=l;i<=r;i++)
		{
			lli p = i;
			while(p)
			{
				digitsCount[i-l][p%10]++;
				p/=10;
			}
		}
		lli cnt =0;
		
		for(lli i=l;i<=r;i++)
		{
			bool flag = false;
			for(lli j=0;j<10;j++)
			{
				if(digitsCount[i-l][j] == v[j])
				{
					flag = true;
					break;
				}
			}
			if(!flag) cnt++;
		}
		cout << cnt << '\n' ;
	}
	return 0;
}