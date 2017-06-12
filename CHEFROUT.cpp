#include <bits/stdc++.h>
using namespace std;
//Created by Deepak Kasera
//On 13/5/2017
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t,n;
	string str;
	cin >> t;
	while(t--)
	{
		cin >> str;
		n = str.length();
		bool flag = false;
		for (int i = 0; i < n - 1; ++i)
		{
			if((str[i]=='E' && str[i+1]=='C') || 
				(str[i]=='S' && (str[i+1]=='E'||str[i+1]=='C')))
			{
				cout << "no\n";
				flag = true;
				break;
			}
		}
		if(!flag) cout << "yes\n";
	}
	return 0;
}