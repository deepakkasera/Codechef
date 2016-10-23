#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int k,r;
	cin>>k>>r;
	int i=1;
	while(k*i % 10 != r && k*i % 10 != 0){
		i++;
	}
	cout<<i;
	return 0;
}