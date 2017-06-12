#include <bits/stdc++.h>
#define LL long long
#define MAXN 200005
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int i,j,k,l,m,n;
	cin >> n;
	set <string> set1;
	set<char> set2;
	unordered_map<string,int> map1;
	string a[200010];
	char b[200010];
	for(i=0;i<n;i++)
	{
		cin>>b[i];
		cin>>a[i];
	}
	int positive=0;
	for(i=0;i<n;i++)
	{
		if(b[i]=='+')
		{
			positive++;
			for(j=0;j<a[i].size();j++)
			{
				map1[a[i].substr(0,j+1)]=1;
			}
		}
	}
	unordered_map<string,int>::iterator it=map1.begin();
	bool boolVar;
	if(positive == n)
	{
		cout<<0;
	}
	else if(positive == 0)
	{
 
		for(i=0;i<n;i++)
		{
			set2.insert(a[i][0]);
		}
		set <char>::iterator it1;
			cout<<set2.size()<<endl;
		for(it1=set2.begin();it1!=set2.end();it1++)
		{
			cout<<*it1<<endl;
		}
 
		}
 
 
	else{
	for(i=0;i<n;i++)
	{
		if(b[i]=='-')
		{
			boolVar=false;
			for(j=1;j<=a[i].size();j++)
			{
				if(map1.count(a[i].substr(0,j))==0)
				{
					set1.insert(a[i].substr(0,j));
					boolVar=true;
					break;
 
				}
 
			}
 
			}
 
			if(!boolVar)
			{
				cout<<-1;
				break;
		}
 
	}
	if(boolVar)
		{
			set <string>::iterator it2;
			cout << set1.size() << endl;
		for(it2=set1.begin();it2!=set1.end();it2++)
		{
			cout << *it2 << endl;
		}
 
		}
	}
	return 0;
}