// #include <bits/stdc++.h>
// using namespace std;
// bool isPrime(int n)
// {
// 	if(n<2 || (n%2==0 && n!=2)) return false;
// 	for(int i=3;i*i<=n;i+=2){
// 		if(!n%i) return false;
// 	}
// 	return true;
// }
// void solve(int n,int &p1,int &p2,int &p3){
// 	// int p1,p2,p3;
// 	for(p3=100;p3>0;p3--){
// 		if(p3*p3*p3 < n && isPrime(p3)){
// 			for(p2=2;p2*p2+p3*p3*p3<n;p2++){
// 				p1 = n-p2*p2-p3*p3*p3;
// 				if(isPrime(p1) && isPrime(p2)){
// 					// cout << p1 << " " << p2 << " " << p3 << endl;
// 					return ;
// 				}
// 			}
// 		}
// 	}
// 	p1=p2=p3=0;
// }
// int main(int argc, char const *argv[])
// {
// 	int n,p1,p2,p3;
// 	while(cin>>n && n)
// 	{
// 		solve(n,p1,p2,p3);
// 		cout << p1 << " " << p2 << " " << p3 << endl;
// 	}
// 	return 0;
// }
// // #include <cstdio>
 
// // int isprime(int N){
// // 	if(N<2 || (!(N&1) && N!=2))
// // 		return 0;
// // 	for(int i=3; i*i<=N; i+=2){
// // 		if(!(N%i))
// // 			return 0;
// // 	}
// // 	return 1;
// // }
 
// // void solve(int N, int &p1, int &p2, int &p3){
// // 	for(p3=100; p3>0; p3--){
// // 		if(p3*p3*p3<N && isprime(p3)){
// // 			for(p2=2; p2*p2+p3*p3*p3<N; p2++){
// // 				p1=N-p3*p3*p3-p2*p2;
// // 				if(isprime(p2) && isprime(p1))
// // 					return;
// // 			}
// // 		}
// // 	}
// // 	p1=p2=p3=0;
// // }
 
// // int main(){
// // 	int N, p1, p2, p3;
// // 	while(scanf("%d", &N) && N){
// // 		solve(N, p1, p2, p3);	
// // 		printf("%d %d %d\n", p1, p2, p3);
// // 	}
// // }
#include <cstdio>
#include <cmath>
#include <algorithm>
 
using namespace std;
 
const int MAXP = 1000000;
 
int plist[MAXP+1], np = 0;
bool isp[MAXP+1];
 
bool search(int n, int i) {
  int p3 = plist[i];
 
  if (p3 > n/p3 || p3*p3 > n/p3) return false;
  n -= p3*p3*p3;
 
  for (int i = 0; i < np; ++i) {
    if (plist[i] >= n/plist[i]) return false;
    int tmp = n-plist[i]*plist[i];
    if (tmp > MAXP) continue;
    if (isp[tmp]) {
      printf("%d %d %d\n", tmp, plist[i], p3);
      return true;
    }
  }
  return false;
}
 
int main() {
  for (int i = 2; i <= MAXP; ++i) isp[i] = true;
 
  for (int i = 2; i*i <= MAXP; ++i)
    if (isp[i])
      for (int j = i*i; j <= MAXP; j += i)
	isp[j] = false;
  for (int i = 2; i <= MAXP; ++i)
    if (isp[i])
      plist[np++] = i;
 
  int n;
  while (scanf("%d", &n) == 1 && n) {
    //for (n = 63; ; n += 2) {
    int rt = int(powf(double(n), 1.0/3.0));
    int id = lower_bound(plist, plist+np, rt)-plist;
 
    id = min(id,np-1);
    
    while (id >= 0 && !search(n, id)) id--;
    if (id < 0) printf("0 0 0\n");
  }
}
