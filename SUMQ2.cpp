#include <bits/stdc++.h>
#define MOD long(1000000007)
#define ll unsigned long long int
using namespace std;

int vectorSearchLower(ll v[], int start, int end, ll x)
{
    if (start > end)
        return -1;
 
    if (x >= v[end])
        return end;
 
    int middle = (start+end)/2;
 
    if (middle > 0 && v[middle-1] <= x && x < v[middle])
        return middle-1;
 
    if (x < v[middle])
        return vectorSearchLower(v, start, middle-1, x);
    return vectorSearchLower(v, middle+1, end, x);
}
int vectorSearchUpper(ll v[], int start, int end, ll x)
{
  int middle;
  if(x <= v[start])
    return start;
  if(x > v[end])
    return -1;
  middle = (start + end)/2;  
  if(v[middle] < x)
  {
    if(middle + 1 <= end && x <= v[middle+1])
      return middle + 1;
    else
      return vectorSearchUpper(v, middle+1, end, x);
  }
    if(middle - 1 >= start && x > v[middle-1])
      return middle;
    else
      return vectorSearchUpper(v, start, middle - 1, x);
 
}
int main(int argc, char const *argv[]) {
        int testCases;
        cin >> testCases;
        while(testCases--)
        {
                int p,q,r;
                cin>>p>>q>>r;
                ll a[p],b[q],c[r];
                ll prefixSumA[p],prefixSumC[r];
                ll sum=0;
                for(int i=0;i<p;i++) 
                  cin>>a[i];
                for(int i=0;i<q;i++) 
                  cin>>b[i];
                for(int i=0;i<r;i++) 
                  cin>>c[i];
                sort(a,a+p);
                sort(b,b+q);
                sort(c,c+r);
                for(int i=0;i<p;i++)
                {
                        sum=(sum+a[i]%MOD)%MOD;
                        prefixSumA[i]=sum;
                }
                sum=0;
                for(int i=0;i<r;i++)
                {
                        sum=(sum+c[i]%MOD)%MOD;
                        prefixSumC[i]=sum;
                }
                int s = vectorSearchUpper(b,0,q-1,max(a[0],c[0]));
                ll ans=0;
                if(s == -1)
                {
                  cout << "0\n";
                  continue;
                }
                for(int i=s;i<q;i++)
                {
                  int x=vectorSearchLower(a,0,p-1,b[i]);
                  int y=vectorSearchLower(c,0,r-1,b[i]);
                  ll ans1=prefixSumA[x]+((x+1)*b[i]%MOD)%MOD;
                  ll ans2=prefixSumC[y]+((y+1)*b[i]%MOD)%MOD;
                  ans+=(ans1%MOD*ans2%MOD)%MOD;
                } 
                cout<<ans%MOD<<'\n';
        }
        return 0;
}