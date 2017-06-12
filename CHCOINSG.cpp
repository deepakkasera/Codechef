#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n%6==0)
			cout << "Misha\n";
		else cout << "Chef\n";
	}
	return 0;
}	