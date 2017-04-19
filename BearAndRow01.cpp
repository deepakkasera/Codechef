#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int testCases;
	string str;
	cin >> testCases ;
	while(testCases--){
		cin>>str;
		long long result = 0;
		int noOfZeroes = 0;
		int x = 0;
		for(int i=str.length()-1;i>=0;i--)
		{
			if(str[i] == '0') noOfZeroes++;
			else{
				if(noOfZeroes!=0) noOfZeroes++;
				noOfZeroes += x;
				x = noOfZeroes;
				result += x;
				noOfZeroes = 0;
			}
		}
		cout << result << '\n';
	}
	return 0;
}