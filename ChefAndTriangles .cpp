#include <bits/stdc++.h>
#define ll long long 
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	ll l,r;
	cin >> n >> l >> r;
	std::vector<ll> v(n);
	for(int i=0;i<n;i++) cin >> v[i];
	sort(v.begin(),v.end());
    ll a,b,c,d,count=0,minus=0;
    for(int i=0;i<n-1;i++){
    	a = v[i];
    	b = v[i+1];
    	if(i==0){
    		c = b-a+1;
    		d = b+a-1;
    	}
    	else{
    		if(d>=b-a+1 && c<=b-a+1){
    			d=b+a-1;
    		}
    		else if (d>=b-a+1){
    			d=b+a-1;
    			minus=b-a+1-d;
    		}
    		else if (c>=b+a-1){
    			c=b-a+1;
    			d=d;
    			minus = c-(b+a-1);
    		}
    		else if(c>=b-a+1 && d>=b+a-1){
    			c=b-a+1;
    			d=d;
    		}
    		else if(c>=b-a+1 && d<=b+a-1){
    			c=b-a+1;
    			d=b+a-1;
    		}
    	}
    }
    if(c<l) c=l;
    else if (d>r) d=r;
    count+=(d-c+1);
    count-=minus;
    //cout << c << " " << d << endl;
    cout << count << endl;
	return 0;
}