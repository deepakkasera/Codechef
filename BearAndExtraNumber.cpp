#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,n;
	cin >> t;
	while(t--){
		cin >> n;
		std::vector<int> v(n);
		for(int i=0;i<n;i++) cin>>v[i];
		sort(v.begin(),v.end());
	    int ans; 
	    if(v[0]!=v[1]-1){ans=v[0];}
	    else if(v[n-1]!=v[n-2]+1){ans=v[n-1];}
	    else{
	    	for(int i=1;i<n-1;i++){
	    	if(!(v[i]==v[i-1]+1 && v[i]==v[i+1]-1)) 
	    		ans=v[i];
	    }
	}
	    cout<<ans<<endl;
	}
	return 0;
}