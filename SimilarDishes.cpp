#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	std::vector<string> v1(4);
	std::vector<string> v2(4);
	while(t--){
		int cnt=0;
		for(int i=0;i<4;i++)
			cin >> v1[i];
		for(int i=0;i<4;i++)
			cin >> v2[i];
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(v1[i] == v2[j])
					cnt++;
			}
		}
		if(cnt >= 2) cout << "similar\n";
		else cout << "dissimilar\n";
	}
	return 0;
}