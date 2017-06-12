#include <bits/stdc++.h>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    long long int t;cin>>t;
    while(t--)
        {
        long long int n;
        cin>>n;
        long long int a[n],b[n];
        b[0]=0;
        for(long long int i=0;i<n;i++)
            {
            cin>>a[i];
        }
        long long int sum=0;
       for(long long int i=1;i<n;i++)
            {
           b[i]=max(abs(a[i]-a[i-1]) , abs(a[i]-1));
           b[i]=max(b[i],abs(1-b[i-1]));
           sum+=b[i];
       }
        cout<<sum<<endl;;
    }
    
    return 0;
}