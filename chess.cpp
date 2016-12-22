#include <bits/stdc++.h>
using namespace std;
int countMoves(int i,int j,int m,int n)   //i and j is starting point 
{
	//Base case
  if(i==m-1 && j==n-1)  return 1;
  int x=0,y=0;
  if(i+2<m && j+1<n)
      x = countMoves(i+2,j+1,m,n);
  if(i+1<m && j+2<n)
     y = countMoves(i+1,j+2,m,n);
  return x+y;
}
int main(int argc, char const *argv[])
{
	int m,n;
	cin >> m >> n;
    cout << countMoves(0,0,m,n) << endl;
	return 0;
}