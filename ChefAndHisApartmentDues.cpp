#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,count =0,index,flag=0;
		cin >> n;
		index=n;
		std::vector<int> v(n);
		for(int i=0;i<n;i++){
			cin >> v[i];
			if(v[i] == 0 && flag == 0){
				flag = 1;
				index = i;
			}
		}
		for(int i=index;i<n;i++){
			if(v[i] == 0) count+=1100;
			if (v[i] == 1) count += 100;
		}
		cout << count << endl;
	}
	return 0;
}