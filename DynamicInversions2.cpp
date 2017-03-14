#include <bits/stdc++.h>
using namespace std;
int BITree[1000010];
int query(int index){
	int sum=0;
	while(index>0){
		sum+=BITree[index];
		index -= (index&(-index));
	}
	return sum;
}
void update(int index,int val,int n){
	while(index<=n){
		BITree[index]+=val;
		index += (index&(-index));
	}
}
int main(int argc, char const *argv[])
{
	int n,q,x,y,max2=INT_MIN;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++){
		cin >> a[i];
		max2 = max(max2,a[i]);
	}
	int count=0,c;
	for(int i=0;i<=max2;i++)
		BITree[i]=0;
	for(int i=n-1;i>=0;i--){
		c=query(a[i]-1);
		count += (c%2);
		count%=2;
		update(a[i],1,max2); 
	}
	while(q--){
		cin>>x>>y;
		count=!count;
		cout<<count<<endl;
	}
	return 0;
}