#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases,n;
	string l1,l2,l3;
	cin >> testCases;
	while(testCases--){
		cin >> l1 >> l2 >> l3;
		cin >> n;
		string index = "";
		int count1=0,count2=0,count3=0;
		for (int i = 0; i < l1.length(); ++i){
			if(l1[i] == '1') count1 ++;
		}
		for (int i = 0; i < l2.length(); ++i){
			if(l2[i] == '1') count2 ++;
		}
		for (int i = 0; i < l3.length(); ++i){
			if(l3[i] == '1') count3 ++;
		}
		//cout << count1 << " " << count2 << " " << count3 << endl;
		cout << count1 + n*count2 + count3 << endl;
	}
	return 0;
}