#include <vector>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <queue>
#include <cstdio>
#include <functional>
using namespace std;
#define gc getchar
#define all(c) c.begin(), c.end()
#define it(a) typeof(a.begin())
#define rit(a) typeof(a.rbegin())
#define f(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b,c) for(int i=a;i!=b;i+=c)
#define traverse(a,i) for(it(a) i=a.begin();i!=a.end();i++)
#define pb push_back
#define mp make_pair
#define MOD long(1000000007)
#define for_each_testcase int t; cin>>t; while(t--)
typedef map<int,int> mii;
typedef pair<long,long> ii;
typedef std::vector<long> vi;
typedef std::vector< std::vector< ii > > AdjList;
typedef unsigned long long ull;
typedef unsigned long long int ll;
int vectorSearchstarter(ll arr[], int start, int end, ll x)
{
 
    if (start > end)
        return -1;
 
    if (x >= arr[end])
        return end;
 
    int mid = (start+end)/2;
 
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid])
        return mid-1;
 
    if (x < arr[mid])
        return vectorSearchstarter(arr, start, mid-1, x);
    return vectorSearchstarter(arr, mid+1, end, x);
}
int vectorSearchUpper(ll arr[], int start, int end, ll x)
{
  int mid;
 
  /* If x is smaller than or equal to the first element,
    then return the first element */
  if(x <= arr[start])
    return start;
 
  /* If x is greater than the last element, then return -1 */
  if(x > arr[end])
    return -1;
 
  /* get the index of middle element of arr[start..end]*/
  mid = (start + end)/2;  /* start + (end - start)/2 */
 
  /* If x is same as middle element, then return mid */
 
 
  /* If x is greater than arr[mid], then either arr[mid + 1]
    is ceiling of x or ceiling lies in arr[mid+1...end] */
   if(arr[mid] < x)
  {
    if(mid + 1 <= end && x <= arr[mid+1])
      return mid + 1;
    else
      return vectorSearchUpper(arr, mid+1, end, x);
  }
 
  /* If x is smaller than arr[mid], then either arr[mid]
     is ceiling of x or ceiling lies in arr[mid-1...end] */
 
    if(mid - 1 >= start && x > arr[mid-1])
      return mid;
    else
      return vectorSearchUpper(arr, start, mid - 1, x);
 
}
int main(int argc, char const *argv[]) {
        for_each_testcase
        {
                int p,q,r,i;
                scanf("%d %d %d",&p,&q,&r);
                ll a[p],b[q],c[r];
                ll prefixSumA[p],prefixSumC[r];
                ll sum=0;
                f(i,p) scanf("%llu",&a[i]);
                f(i,q) scanf("%llu",&b[i]);
                f(i,r) scanf("%llu",&c[i]);
                sort(a,a+p);
                sort(b,b+q);
                sort(c,c+r);
                // cout<<"MOD"<<' '<<MOD<<'\n';
                for(i=0;i<p;i++)
                {
                        sum=(sum+a[i]%MOD)%MOD;
                        prefixSumA[i]=sum;
                }
                sum=0;
                for(i=0;i<r;i++)
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
                for(i=s;i<q;i++)
                {
                        int l=vectorSearchstarter(a,0,p-1,b[i]);
                        int s2=vectorSearchstarter(c,0,r-1,b[i]);
                        // l=2;s2=1;
                        // cout<<l<<' '<<s2<<'\n';
                        ll a1=prefixSumA[l],a2=prefixSumC[s2];
                        // cout<<a1<<' '<<a2<<'\n';
                        ll sum1=prefixSumA[l]+((l+1)*b[i]%MOD)%MOD;
                        ll sum2=prefixSumC[s2]+((s2+1)*b[i]%MOD)%MOD;
                        ans+=(sum1%MOD*sum2%MOD)%MOD;
                }
 
                cout<<ans%MOD<<'\n';
        }
        return 0;
}