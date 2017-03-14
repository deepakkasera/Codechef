#include <bits/stdc++.h>
using namespace std;
int inversions=0;
int merge(int b[],int *left,int leftCount,int *right,int rightCount){
	int i=0,j=0,k=0,cnt=0;
	while(i<leftCount && j<rightCount){
		if(left[i] < right[j]){
			b[k++]=left[i++];
		}
		if(left[i] >= right[j]){
			cnt+=(leftCount-i);
			b[k++]=right[j++];
		}
	}
	while(i<leftCount) b[k++]=left[i++];
	while(j<rightCount) b[k++]=right[j++];
	return cnt;
}
int mergeSort(int b[],int n){
	if(n<2) return 0;
	int* left = NULL;
	int *right = NULL;
	int middle=n/2;
	left = new int[middle];
	right = new int[n-middle];
	for(int i=0;i<middle;i++)
		left[i]=b[i];
	for(int i=middle;i<n;i++)
		right[i-middle]=b[i];
	mergeSort(left,middle);
	mergeSort(right,n-middle);
	inversions += merge(b,left,middle,right,n-middle);
	delete left;
	delete right;
	return inversions;
}
int main(int argc, char const *argv[])
{
	int n,q,x,y;
	cin >> n >> q;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	while(q--){
		cin >> x >> y;
		swap(a[x-1],a[y-1]);
		int b[n];
		for(int i=0;i<n;i++)b[i]=a[i];
		cout<<mergeSort(b,n)%2<<endl;
		inversions=0;
	}
	return 0;
}