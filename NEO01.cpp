#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int testCases;
	cin >> testCases;
	ll finalResult=0;
	while(testCases--)
	{
		ll n;
		cin >> n;
		std::vector<ll> v(n);
		std::vector<ll> vec;
		ll countPos=0,countNeg=0,pos=0,neg=0,z=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		for(int i=0;i<n;i++){
			if(v[i] >= 0){
				countPos += v[i];
				pos++;
			}
			else{
				vec.push_back(v[i]);
				countNeg+=v[i];
				neg++;
			}
		}
		if(countPos == 0 || pos == 0){
			cout << countNeg << endl;
		}
		else{
			ll result=0;
			result = countPos*pos;
			if(neg != 0){
				sort(vec.begin(),vec.end(),greater<ll>());
				ll sum = countPos;
				int i;
				for(i=0;i<vec.size();i++){
					sum += vec[i];
					pos++;
					if(sum*pos > result)
					  result = sum*pos;
					else break; 
				}
				while(i < vec.size()){
					result += vec[i];
					i++;
				}
			}
			cout << result << endl;
		}
	}
	return 0;
}
