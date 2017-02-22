#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int t,o1,o2,n;
	cin >> t ;
	while(t--){
		cin >> o1 >> o2;
		n = o1*o2;
		std::vector<int> v(n);
		for(int i=0;i<n;i++) cin >> v[i];
 		int m=n+o2-1;
		v.resize(m);
		bool flag=false;
		for(int i=n;i<m;i++)  v[i] = v[i-n];
		std::vector<int> cumm(m+1,0);
	    for(int i=1;i<=m;i++){
	    	cumm[i] = cumm[i-1]+v[i-1];
	    }
	    //for(int i=0;i<=m;i++) cout << cumm[i] << " ";
	    for(int i=0;i<o2;i++){
	    	int cnt=0;
	    	for(int j=0;j<m;j+=o2){
	    		int sum=0;
	    		sum = cumm[i+(j+1)*m] - cumm[i+j*m];
	    		if(sum > o2/2) cnt++;
	    	}
	    	if(cnt > o1/2){
	    		cout << "1\n";
	    		flag = true;
	    		break;
	    	}
	    }
	    if(!flag) cout << "0\n";
	}
	return 0;
}