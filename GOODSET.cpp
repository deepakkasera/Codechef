#include <bits/stdc++.h>
#define MAXN 107
// #define push_back PBI

using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int testCases,no;
	cin >> testCases;
	while(testCases--){
		cin >> no;
		std::vector<int> numbers;
		int variable;
		for (int i = 1; i <= no; ++i)
		{
			if(i == 1) numbers.push_back(1);
			else if(i == 2) numbers.push_back(2);
			else if(i == 3) numbers.push_back(4);
			else
			{
				variable = numbers[numbers.size()-1]+3;
				if(variable <= 500) numbers.push_back(variable);
			}
			/* code */
		}
		for(int i=0;i<numbers.size();i++){
			cout << numbers[i] << " ";
		}
		cout << endl;
	}
	return 0;
}