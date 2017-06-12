#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int testcases,n,a;
	cin >> testcases;
	while(testcases--){
		cin >> n;
		int result = 0;
		for(int i=1;i<=n;i++){
			cin >> a;
		    result = max(result,a);
		}
		cout << n - result << '\n';
	}
	return 0;
}